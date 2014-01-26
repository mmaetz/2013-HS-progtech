/* Programming Techniques for Scientific Simulations, HS 2013
 * Exercise 12
 */

#include <vector>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <sys/time.h>
using namespace std;

typedef double value_type;
typedef std::vector<value_type> matrix_type;
typedef matrix_type::size_type size_type;

void set(matrix_type& A, matrix_type& B, const size_type n);
void print(const matrix_type& A, const size_type n);

typedef void (*mult_function)(const matrix_type& A, const matrix_type& B, matrix_type& C, const size_type n);
double benchmark(mult_function f, size_type n_iterations, matrix_type& A, matrix_type& B, matrix_type& C, const size_type n);

void mult(const matrix_type& A, const matrix_type& B, matrix_type& C, const size_type n);
void mult1(const matrix_type& A, const matrix_type& B, matrix_type& C, const size_type n);
void mult2(const matrix_type& A, const matrix_type& B, matrix_type& C, const size_type n);
void mult3(const matrix_type& A, const matrix_type& B, matrix_type& C, const size_type n);
void mult4(const matrix_type& A, const matrix_type& B, matrix_type& C, const size_type n);

extern "C"
{
    // Implements C = alpha*A*B + beta*C
    void dgemm_(const char& TRANSA , const char& TRANSB,
                const int& M, const int& N, const int& K,
                const double& alpha , const double* A, const int& LDA,
                const double* B, const int& LDB,
                const double& beta , double* C, const int& LDC) ;
}

int main()
{

#ifndef NDEBUG
    const size_type n = 8;
#else
    const size_type n = 2048;
#endif
    int n_iterations = 1;
    
    matrix_type A(n*n), B(n*n), C(n*n);
    
#ifndef NDEBUG
    set(A,B,n);
    print(A, n);
    cout << "*" << endl;
    print(B, n);
#endif
    
    stringstream ss;
    ss << n;
    
    cout << "mult..." << endl;
    ss << "\t" << benchmark(mult,n_iterations,A,B,C,n);

    cout << "mult1..." << endl;
    ss << "\t" << benchmark(mult1,n_iterations,A,B,C,n);

    cout << "mult2..." << endl;
    ss << "\t" << benchmark(mult2,n_iterations,A,B,C,n);

    cout << "mult3..." << endl;
    ss << "\t" << benchmark(mult3,n_iterations,A,B,C,n);

    cout << "mult4..." << endl;
    ss << "\t" << benchmark(mult4,n_iterations,A,B,C,n);

    cout << "** RESULTS **" << endl;
    cout << "N\ttrivial\tjki\ttranspose\tpointers+jki\tblas" << endl;
    cout << ss.str() << endl;
}

double benchmark(mult_function f, size_type n_iterations, matrix_type& A, matrix_type& B, matrix_type& C, const size_type n)
{
    set(A,B,n);
    
    timeval start, end;
    gettimeofday(&start, NULL);
    for (size_type i = 0; i < n_iterations; ++i)
    {
        f(A, B, C, n);
    }
    gettimeofday(&end, NULL);

#ifndef NDEBUG
    cout << "C = " << endl;
    print(C, n);
#endif

    return (end.tv_sec - start.tv_sec)+1e-6*(end.tv_usec - start.tv_usec);
}

void set(matrix_type& A, matrix_type& B, const size_type n)
{
    srand48(42);
    for (size_type i=0; i<n; ++i) {
        for (size_type j=0; j<n; ++j) {
            A[i+j*n] = int(drand48()*2);
            B[i+j*n] = int(drand48()*2);
        }
    }
}

void print(const matrix_type& A, const size_type n)
{
    for (size_type i=0; i<n; ++i) {
        for (size_type j=0; j<n; ++j) {
            cout << A[i*n+j] << " ";
        }
        cout << endl;
    }
}


// Trivial implementation
void mult(const matrix_type& A, const matrix_type& B, matrix_type& C, const size_type n)
{
    for (size_type i=0; i<n; ++i) {
        for (size_type j=0; j<n; ++j) {
            C[i+j*n] = 0;
            for (size_type k=0; k<n; ++k) {
                C[i+j*n] += A[i+k*n] * B[k+j*n];
            }
        }
    }
}

// Inverting loops for cache effects
void mult1(const matrix_type& A, const matrix_type& B, matrix_type& C, const size_type n)
{
    for (size_type i = 0; i < n*n; ++i)
        C[i] = 0;
    
    for (size_type j = 0; j < n; j++)
        for (size_type k = 0; k < n; ++k)
            for (size_type i = 0; i < n; ++i)
                C[i+j*n] += A[i+k*n]*B[k+j*n];
}

// Using transpose for linear access in last loop + reduction in local variable
void mult2(const matrix_type& A, const matrix_type& B, matrix_type& C, const size_type n)
{
    matrix_type D(n*n);
    for (size_type i = 0; i < n; ++i)
        for (size_type j = 0; j < n; ++j)
            D[i+j*n] = A[j+i*n];
    
    for (size_type i = 0; i < n; ++i)
    {
        for (size_type j = 0; j < n; ++j)
        {
            value_type out = 0;
            const value_type *in1 = &D[i*n], *in2 = &B[j*n];
            for (size_type k = 0; k < n; ++k, ++in1, ++in2)
                out += (*in1) * (*in2); // C[i+j*n] += D[k+i*n] * B[k+j*n];
            C[i+j*n] = out;
        }
    }
}

// Inverse loop orders + moving index computations out of inner loop
void mult3(const matrix_type& A, const matrix_type& B, matrix_type& C, const size_type n)
{
    for (size_type j=0; j<n; ++j)  {
        for (value_type* p=&C[0]+j*n; p<&C[0]+(j+1)*n; ++p)
            *p = 0;

        for (size_type k=0; k<n; ++k) {
            const value_type  b =  B[k+j*n];
            const value_type* a = &A[0+k*n];
            value_type      * c = &C[0+j*n];
            for (size_type i=0; i<n; ++i, ++a, ++c)
                *c += *a * b; // C[i+j*n] += A[i+k*n] * B[k+j*n];
        }
    }
}

// BLAS DGEMM
void mult4(const matrix_type& A, const matrix_type& B, matrix_type& C, const size_type n)
{
    value_type one=1, zero=0;
    
    dgemm_('N', 'N',
           n, n, n,
           one, &A[0], n,
           &B[0], n,
           zero, &C[0], n);
}


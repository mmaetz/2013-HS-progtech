/* Programming Techniques for Scientific Simulations, HS 2013
 * Exercise 12.1
 */

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <sys/time.h>

typedef std::vector<double> matrix_type;

#define N 1000

void set(matrix_type& A, matrix_type& B)
{
  for (int i=0; i<N; ++i)
    for (int j=0; j<N; ++j){
      A[i*N+j] = drand48();
      B[i*N+j] = drand48();
    }
}

void multiply_simple(const matrix_type& A, const matrix_type& B, matrix_type& C)
{
  // ...
    
}

void print(const matrix_type& A)
{
  for(int i=0; i<N; ++i){

    for(int j=0; j<N; ++j)
      std::cout << A[i*N+j] << " ";

    std::cout << std::endl;
  }
}

int main() 
{
  const int num_iter = 100;
	
  matrix_type A(N*N), B(N*N), C(N*N);
    
  set(A, B);
    
  timeval start, end;
  gettimeofday(&start, NULL);

  for (int i = 0; i < num_iter; ++i)
    multiply_simple(A, B, C);

  gettimeofday(&end, NULL);

  std::cout << N << " " << (end.tv_sec - start.tv_sec)+1e-6*(end.tv_usec - start.tv_usec) << std::endl;
}

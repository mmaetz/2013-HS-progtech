/* Programming Techniques for Scientific Simulations, HS 2013
 * Exercise 4.2
 */

#include <vector>
#include <iostream>
#include <iomanip>
#include <sys/time.h>

using namespace std;

typedef int array_t;

int main()
{    
    timeval start, end;
    
    const size_t elm_size = sizeof(array_t);
    
    const size_t MINSIZE = 8 / elm_size;
    const size_t MAXSIZE = 32 * 1024 * 1024 / elm_size;
    const size_t MAXSTEP = 128 / elm_size;
    const size_t UNROLLFAC = 8;
    const size_t NOPS    = 8 * MAXSIZE;
        
    array_t* arr = new array_t[MAXSIZE];
    for (size_t n=MINSIZE; n<=MAXSIZE; n*=2) {
        array_t* arr_end = arr + n;
        for(size_t step=1; step<=std::min(MAXSTEP,n/UNROLLFAC); step*=2) {
            
            const size_t num_steps = n / step;
            const size_t num_sweeps = NOPS / num_steps;
            
            for( size_t i = 0; i < num_steps; ++i, i += step )
                arr[i] = 0;
            
            
            gettimeofday(&start, NULL);
            
            for( size_t sweep = 0; sweep < num_sweeps; ++sweep )
            {
                array_t* p = arr;
                while( p < arr_end )
                {
                    for( size_t i = 0; i < UNROLLFAC; ++i, p += step )
                        ++(*p);
                }
            }
            
            gettimeofday(&end, NULL);
            double time = end.tv_sec - start.tv_sec + 1e-6 * (end.tv_usec - start.tv_usec);
            double mops = num_steps * num_sweeps / (time * 1e6);
            
            cout << setprecision(12)
            << setw(16) << double(n) * elm_size / (1024)
            << setw(16) << step * elm_size
            << setw(16) << time
            << setw(16) << mops
            << endl;
        }
    }
    
    delete[] arr;
    
    return 0;
}
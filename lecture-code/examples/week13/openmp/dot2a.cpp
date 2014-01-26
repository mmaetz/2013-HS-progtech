#include <iostream>
#include <vector>
#include <algorithm>
#include <omp.h>

int main()
{
    unsigned long const N = 100;
    std::vector<int> a(N, 2), b(N, 3);
    
    int nthreads = omp_get_num_threads();
    std::vector<int> c(nthreads,0);
    
#pragma omp parallel for
    for (std::size_t i = 0; i < N; ++i)
        c[omp_get_thread_num()] += a[i] * b[i];
    
    double sum = std::accumulate(c.begin(), c.end(), 0.);
    
    std::cout << "Dot product is " << sum << std::endl;
}
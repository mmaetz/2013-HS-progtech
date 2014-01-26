#include <iostream>
#include <sys/time.h>

inline double function(const double x) 
{
  return x*x;
}

double integrate(const double a, const double b, const unsigned bins) 
{
  const unsigned int steps = 2*bins + 1;

  const double dr = (b - a) / (steps - 1); // 2 flops

  double I = function(a); // 1 flop
  
  for(unsigned int i = 1; i < steps-1; ++i) // steps-2 times = 2*bins-1 times
    I += 2 * (1.0 + i%2) * function(a + dr * i); // 7 flops

  I += function(b); // 1+1 flops
  
  return I * (1./3) * dr; // 2 flops
}

int main() {

  const unsigned int bins = 5;

  for (int bins=100; bins<=100000; bins+=100) {
      struct timeval t;
      gettimeofday(&t, NULL);
      double t_start=t.tv_sec+(t.tv_usec/1000000.0);
      
      double res = integrate(0,4,bins);
      
      gettimeofday(&t, NULL);
      double elapsed_time=t.tv_sec+(t.tv_usec/1000000.0)-t_start;
      
      std::cout << bins << "\t" << res << "\t" << elapsed_time << std::endl;
  }
    
  return 0;
}

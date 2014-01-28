/* Programming Techniques for Scientific Simulations, HS 2013
 * Exercise 2.2
 */

#include <iostream>
#include <cmath>

inline double sin(const double x) 
{
  return std::sin(x);
}

double integrate(const double a, const double b, const unsigned bins, double (*f)(const double)) 
{
  const unsigned int steps = 2*bins + 1;

  const double dr = (b - a) / (steps - 1);

  double I = f(a);
  
  for(unsigned int i = 1; i < steps-1; ++i)
    I += 2 * (1.0 + i%2) * f(a + dr * i);

  I += f(b);
  
  return I * (1./3) * dr;
}

int main() {

  const unsigned int bins = 5;
  double (*functionpointer)(const double) = sin;

  std::cout.precision(15);
  std::cout 
    << "I = " << integrate(0,M_PI,bins,functionpointer) << "   (exact: 2.0)" 
    << std::endl;
    
  return 0;
}

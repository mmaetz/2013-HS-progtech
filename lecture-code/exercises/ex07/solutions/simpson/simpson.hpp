/* Programming Techniques for Scientific Simulations, HS 2013
 * Exercise 7
 */

#ifndef SIMPSON_HPP
#define SIMPSON_HPP

#include <cstdlib>
#include <cassert>

template<class F, typename T>
T integrate(const T a, const T b, const unsigned bins, const F& func)
{
  assert(bins > 0);

  const unsigned int steps = 2*bins + 1;

  const T dr = (b - a) / (steps - 1);

  T I = func(a);
  
  for(unsigned int i = 1; i < steps-1; ++i)
    I += 2 * (1.0 + i%2) * func(a + dr * i);

  I += func(b);
  
  return I * (1./3) * dr;
}

#endif

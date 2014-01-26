/* Programming Techniques for Scientific Simulations, HS 2013
 * Exercise 10.2
 */

#include <cmath>
#include <cstdlib>
#include <cassert>

class function
{
public:
  virtual double operator()(const double) const = 0;
};

double integrate(const double a, const double b, const unsigned bins, const function& func);

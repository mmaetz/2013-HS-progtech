/* Programming Techniques for Scientific Simulations, HS 2013
 * Exercise 10.2
 */

#include <cmath>
#include <iostream>
#include <cstdlib>
#include <cassert>

class function
{
public:
  virtual double operator()(const double) const = 0;
};

double integrate(const double a, const double b, const unsigned bins, const function& func)
{
  assert(bins > 0);
  assert(b >= a);

  const unsigned steps = 2*bins + 1;

  const double dr = (b - a) / (steps - 1);

  double I = func(a);
  
  for(unsigned i = 1; i < steps-1; ++i)
    I += 2 * (1.0 + i%2) * func(a + dr * i);

  I += func(b);
  
  return I * (1./3) * dr;
}

class sin_lambda_x : public function
{

public:

  sin_lambda_x(const double lambda=1.0)
    : lambda_(lambda)
  {}
    
  double operator()(const double x) const { return std::sin(lambda_*x); }

private:

  const double lambda_;
};

int main()
{
  const unsigned bins = 5;

  const double a(0.0), b(M_PI);

  const double lambda = 2.2;
  
  sin_lambda_x func(lambda);

  std::cout.precision(15);
  std::cout << "I = " << integrate(a,b,bins,func) << std::endl;

  return 0;
}

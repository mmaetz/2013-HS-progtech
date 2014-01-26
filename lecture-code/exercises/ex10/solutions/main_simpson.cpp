/* Programming Techniques for Scientific Simulations, HS 2013
 * Exercise 10.2
 */

#include <iostream>

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

/* Programming Techniques for Scientific Simulations, HS 2013
 * Exercise 9.1
 */

#include <cmath>
#include <iostream>

#include "simpson.hpp"

class sin_lambda_x 
{

public:

    sin_lambda_x(const double lambda=1.0)
    : lambda_(lambda)
    {}

    double operator()(const double x) const { return std::sin(lambda_*x); }

private:

    double lambda_;
};

int main() {

    const unsigned int bins = 5;
    const double lambda = 2.2;

    sin_lambda_x func(lambda);

    std::cout.precision(15);
    std::cout << "I = " << integrate(0,1u,bins,func) << std::endl;

    return 0;
}

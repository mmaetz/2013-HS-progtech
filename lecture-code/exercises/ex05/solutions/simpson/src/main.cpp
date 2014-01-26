/* Programming Techniques for Scientific Simulations, HS 2013
 * Exercise 5.1
 */

#include <cmath>
#include <iostream>

#include "simpson.hpp"

int main() {

  const unsigned int bins = 5;

  std::cout.precision(15);
  std::cout << "I = " << integrate(0,M_PI,bins,std::sin) << std::endl;
    
  return 0;
}

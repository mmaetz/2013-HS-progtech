/* Programming Techniques for Scientific Simulations, HS 2013
 * Exercise 1.5
 */

// Output: macheps for double = 1.0842e-19 (2.22045e-16 theoretical)

#include <iostream>
#include <limits>

double macheps() {

  const double beta(1.0); 
  double alpha(1.0);

  while(double(alpha+beta)>beta)
    alpha /= 2;

  return alpha*2;
}

int main() 
{

  std::cout 
    << "macheps for double = "<< macheps() << ' '
    << '(' << std::numeric_limits<double>::epsilon() << " theoretical)"
    << std::endl;
        
  return 0;
}

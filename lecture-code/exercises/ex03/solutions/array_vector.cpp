/* Programming Techniques for Scientific Simulations, HS 2013
 * Exercise 3.1a
 */

#include <iostream>
#include <vector>

int main() 
{
	std::vector<double> alloc;

  double sum(0); double temp(0);
  while(std::cin >> temp) {
		alloc.push_back(temp);
		sum+=temp;
		std::cout << "size:" << std::endl;
		std::cout << alloc.size() << std::endl;
	};
	std::cout << "result:" << std::endl;
  for(std::vector<double>::iterator it=alloc.end()-1; it >=alloc.begin(); --it)
	{
    std::cout << *it/sum << std::endl;
	}
	std::cout << "end size:" << std::endl;
	std::cout << alloc.size() << std::endl;

  return 0;
}

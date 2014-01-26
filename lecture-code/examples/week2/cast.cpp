#include <iostream>

int main()
{
  float y=3.f;
  std::cout << "y = " << y << std::endl;
  std::cout << "static_cast<int>(y) = " << static_cast<int>(y) << std::endl;
  std::cout << "*reinterpret_cast<int*>(&y) = " << *reinterpret_cast<int*>(&y)
            << std::endl;
}

#include <iostream>

int main()
{
  int i=3;
  int *p=&i;
  *p=257;
  std::cout << i << "\n";
}

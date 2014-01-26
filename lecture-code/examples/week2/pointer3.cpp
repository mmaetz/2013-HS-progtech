#include <iostream>

int main()
{
  int i=3;
  int *p=reinterpret_cast<int*>(reinterpret_cast<char*>(&i)+1);
  *p=257;
  std::cout << i << "\n";
}

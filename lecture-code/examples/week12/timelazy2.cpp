#include "lazyvector.hpp"
#include <iostream>

int main()
{
  const int N=10000000;
  lazyvector<double> a(N), b(N), c(N);
  for (int i=0;i<100;++i)
    a=b+c;
  std::cout << a[0] << std::endl;
}

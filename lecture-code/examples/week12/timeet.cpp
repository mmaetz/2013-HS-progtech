#include "etvector.hpp"
#include <iostream>

int main()
{
  const int N=10000000;
  etvector<double> a(N), b(N), c(N), d(N);
  for (int i=0;i<100;++i)
    a=b+c+d;
  std::cout << a[0] << std::endl;
}

#include "simplevector.hpp"

int main()
{
  const int N=10000000;
  simplevector<double> a(N), b(N), c(N), d(N);
  for (int i=0;i<100;++i)
    a=b+c+d;
}

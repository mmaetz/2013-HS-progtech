#include <iostream>
#include <cmath>
#include "simpson.hpp"

double my(double x) {
  return 3.*sin(3.*x-1);
}

int main() {
      double a, b;
      unsigned int N;
      std::cin >> a >> b >> N;
      std::cout << simpson(&my,a,b,N) << std::endl;
  return 0;
}

#include <iostream>
#include <iomanip>

int main()
{
  int N;
  std::cout << "N? ";
  std::cin >> N;

  float sum;

  sum=0.;
  for (int i=0;i<N;++i)
    sum += 1;
  std::cout << sum << " " << float(N) << std::endl;

  sum=0.;
  for (int i=N;i>0;--i)
    sum += float(i)*float(i);
  std::cout << sum << " " << float(N)*float(N+1)*float(2*N+1)/6. << std::endl;

  sum=0.;
  for (int i=0;i<N;++i)
    sum += float(i+1)*float(i+1);
  std::cout << sum << " " << float(N)*float(N+1)*float(2*N+1)/6. << std::endl;
}

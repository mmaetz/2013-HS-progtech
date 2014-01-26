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

  sum=0.;
  for (int i=0;i<N;i+=1000) {
    float tmp=0.;
    for (int j=0;j<1000;++j)  
      tmp += float(i+j+1)*float(i+j+1);
    sum += tmp;
  }
  std::cout << sum << " " << float(N)*float(N+1)*float(2*N+1)/6. << std::endl;
}

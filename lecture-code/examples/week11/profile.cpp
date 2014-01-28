#include <iostream>
#include <vector>

// Inserting in the beginning is linear.
std::size_t insert_begin() 
{
  std::vector<int> v;
  for (int i=0;i<100000;++i)
    v.insert(v.begin(),1);
  return v.size();
}

// Inserting at the end is constant.
std::size_t insert_end() 
{
  std::vector<int> v;
  for (int i=0;i<100000;++i)
    v.push_back(1);
  return v.size();
}

int main() 
{
	std::cout << insert_begin();
	std::cout << insert_end();
}

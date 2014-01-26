#include <cassert>
#include <algorithm>

template <class T>
class simplevector {
public:
  typedef T value_type;
  typedef T& reference;
  typedef unsigned int size_type;
  
  simplevector(size_type s=0) : p_(new value_type[s]), sz_(s) {}
  simplevector(const simplevector& v) : p_(new value_type[v.size()]), sz_(v.size()) 
  {
    for (int i=0;i<size();++i)
	  p_[i]=v.p_[i];
  }
  ~simplevector() { delete[] p_;}
  
  void swap(simplevector& v)
  {
    std::swap(p_,v.p_);
    std::swap(sz_,v.sz_);
  }
  
  const simplevector& operator=(simplevector v)
  {
    swap(v);
    return *this;
  }

  const simplevector& operator +=(const simplevector& v)
  {
    assert(size()==v.size());
    for (int i=0;i<size();++i)
      p_[i]+=v.p_[i];
    return *this;
  }

  size_type size() const { return sz_;}
  value_type operator[](size_type i) const { return p_[i];}
  reference operator[](size_type i) { return p_[i];}

private:
  value_type* p_;
  size_type sz_;
};

template <class T>
simplevector<T> operator+(const simplevector<T>& x, const simplevector<T>& y)
{
  simplevector<T> result=x;
  result += y;
  return result;
}

#include <cassert>
#include <algorithm>

template <class T>
class vectorsum;

template <class T>
class lazyvector {
public:
  typedef T value_type;
  typedef T& reference;
  typedef unsigned int size_type;
  
  lazyvector(size_type s=0) : p_(new value_type[s]), sz_(s) {}
  lazyvector(const lazyvector& v) : p_(new value_type[v.size()]), sz_(v.size()) 
  {
    for (int i=0;i<size();++i)
	    p_[i]=v.p_[i];
  }
  ~lazyvector() { delete[] p_;}
  
  void swap(lazyvector& v)
  {
    std::swap(p_,v.p_);
    std::swap(sz_,v.sz_);
  }
  
  const lazyvector& operator=(lazyvector v)
  {
    swap(v);
    return *this;
  }
  
  const lazyvector& operator=(const vectorsum<T>& v)
  {
    for (int i=0;i<size();++i)
	    p_[i]=v[i];
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
class vectorsum {
public:
  typedef unsigned int size_type;
  typedef T value_type;
  
  vectorsum(const lazyvector<T>& x, const lazyvector<T>& y)
  : left_(x), right_(y) {}
  
  value_type operator[](size_type i) const
  {
    return left_[i] + right_[i];
  }
  
  
private:
  const lazyvector<T>& left_;
  const lazyvector<T>& right_;
};


template <class T>
inline vectorsum<T> operator+(const lazyvector<T>& x, const lazyvector<T>& y)
{
    return vectorsum<T>(x,y);
}

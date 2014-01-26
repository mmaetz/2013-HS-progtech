#include <cassert>
#include <algorithm>

// This class encapsulates the "+" operation.
struct plus {
public:
    static inline double apply(double a, double b) {
        return a+b;
    };
};

template<typename Left, typename Op, typename Right>
struct X {
	const Left& left_;
	const Right& right_;

    X(const Left& x, const Right& y)
        : left_(x), right_(y)
    { }

    double operator[](int i) const
    { 
	  return Op::apply(left_[i],right_[i]); 
	}
};


template <class T>
class etvector {
public:
  typedef T value_type;
  typedef T& reference;
  typedef unsigned int size_type;
  
  etvector(size_type s=0) : p_(new value_type[s]), sz_(s) {}
  etvector(const etvector& v) : p_(new value_type[v.size()]), sz_(v.size()) 
  {
    for (int i=0;i<size();++i)
	  p_[i]=v.p_[i];
  }
  ~etvector() { delete[] p_;}
  
  void swap(etvector& v)
  {
    std::swap(p_,v.p_);
    std::swap(sz_,v.sz_);
  }
  
  const etvector& operator=(etvector v)
  {
    swap(v);
    return *this;
  }
    
  template <class L, class Op, class R>
  const etvector& operator=(const X<L,Op,R>& v)
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

template<class Left, class T>
inline X<Left, plus, etvector<T> > operator+(const Left& a, const etvector<T>& b)
{
    return X<Left, plus, etvector<T> >(a,b);
}

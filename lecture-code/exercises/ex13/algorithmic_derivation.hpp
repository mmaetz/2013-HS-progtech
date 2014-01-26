/* Programming Techniques for Scientific Simulations, HS 2013
 * Exercise 13
 */

#ifndef ALGO_DERIV__
#define ALGO_DERIV__

enum op {Add, Multiply};

//********

template<class T>
class Constant
{
public:
  Constant(const T v) : _val(v) {}
  T operator()(T) const {/*to be completed*/}
  T derivative(T) const {/*to be completed*/}
private:
  T _val;
};

template <class T>
Constant<T> constant(const T x)
{
  return Constant<T>(x);
}

//********

template <class T>
class Variable
{
public:
  T operator()(const T x) const {/*to be completed*/}
  T derivative(const T x) const {/*to be completed*/}
};

//********

template<class left, class right, op o>
class Expression
{
public:
  Expression(const left _l, const right _r) : l(_l), r(_r) { }
        
  template <class T>
  T operator()(const T x)
  {
    switch (o)
      {
      case Add:
        /*to be completed*/
        break;
      case Multiply:
        /*to be completed*/
        break;
      }
  }
        
  template <class T>
  T derivative(const T x)
  {
    switch (o)
      {
      case Add:
        /*to be completed*/
        break;
      case Multiply:
        /*to be completed*/
        break;
      }
  }
        
private:
  left l;
  right r;
};

template<class L, class R>
Expression<L, R, Multiply> operator*(const L l, const R r)
{
  return Expression<L, R, Multiply>(l, r);
}

template<class L, class R>
Expression<L, R, Add> operator+(const L l, const R r)
{
  return Expression<L, R, Add>(l, r);
}

#endif //ALGO_DERIV__

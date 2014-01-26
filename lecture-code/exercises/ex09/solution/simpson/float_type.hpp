/* Programming Techniques for Scientific Simulations, HS 2013
 * Exercise 9.1
 */
 
#ifndef FLOAT_TYPE_HPP
#define FLOAT_TYPE_HPP

#include <limits>

namespace detail
{
    //--- if-then-else helper meta-function
    template <bool COND, class T1, class T2>
    struct if_else { typedef T2 type; };

    template <class T1, class T2>
    struct if_else<true,T1,T2> { typedef T1 type; };


    //--- Handle types for which numeric_limits is specialized
    // a) both floating point: choose type with larger mantissa
    template <class T1, class T2, bool integer1, bool integer2>
    struct helper2
    {
        typedef typename if_else<(std::numeric_limits<T1>::digits>=std::numeric_limits<T2>::digits),
                                 T1,T2>::type type;
    };

    // b) both integer: choose double
    template <class T1, class T2>
    struct helper2<T1,T2,true,true> { typedef double type; };

    // c) one integer one floating point: choose the floating point type
    template <class T1, class T2>
    struct helper2<T1,T2,true,false> { typedef T2 type; };
    template <class T1, class T2>
    struct helper2<T1,T2,false,true> { typedef T1 type; };


    //--- Handle types for which numeric_limits is not specialized
    // If we don't know anything about either type: don't define type (will cause compiler error)
    template <class T1, class T2, bool both_specialized>
    struct helper1 {};

    // If we get twice the same unknown type just return it
    template <class T>
    struct helper1<T,T,false> { typedef T type; };

    // If we know both types: delegate decision to helper2
    template <class T1, class T2>
    struct helper1<T1,T2,true>
    {
        typedef typename helper2<T1,T2,std::numeric_limits<T1>::is_integer,
                                       std::numeric_limits<T2>::is_integer>::type type;
    };
} // namespace detail

template <class T1, class T2>
struct float_type
{
    // check whether numeric_limits is specialized and delegate to helper1
    typedef typename detail::helper1<T1,T2,std::numeric_limits<T1>::is_specialized
                                        && std::numeric_limits<T2>::is_specialized>::type type; 
};

#endif //FLOAT_TYPE_HPP

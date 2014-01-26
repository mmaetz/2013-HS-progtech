/* Programming Techniques for Scientific Simulations, HS 2013
 * Exercise 9.1
 */

#ifndef SIMPSON_HPP
#define SIMPSON_HPP

#include "float_type.hpp"
#include <cstdlib>
#include <cassert>

template<typename T1, typename T2, class F>
typename float_type<T1,T2>::type integrate(const T1 a, const T2 b, const unsigned bins, const F& func)
{
    assert(bins > 0);
    assert(b >= a);

    const unsigned steps = 2*bins + 1;

    typedef typename float_type<T1,T2>::type FT;
    const FT dr = FT(b - a) / (steps - 1);

    FT I = func(a);

    for(unsigned i = 1; i < steps-1; ++i)
        I += 2 * (1.0 + i%2) * func(a + dr * i);

    I += func(b);

    return I * (1./3) * dr;
}

#endif

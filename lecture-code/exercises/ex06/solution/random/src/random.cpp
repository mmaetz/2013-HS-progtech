#include "random.hpp"

namespace progtech { namespace random
{
    
    // constants from Numerical Recipes
    const Generator::impl_type Generator::a_ = 1664525;
    const Generator::impl_type Generator::c_ = 1013904223;
    const Generator::impl_type Generator::m_ = static_cast<Generator::impl_type>(1ul<<32);

    Generator::result_type Generator::max()
    {
        return m_ - 1;
    }
    
    Generator::Generator(result_type seed)
    :   seed_(seed)
    {
    }
    
    Generator::result_type Generator::operator()()
    {
        // as m_ is a power of 2 we can replace the slow % by a bitwise and with (m_-1)
        seed_ = (a_ * seed_ + c_) & (m_ - 1);
        return seed_;
    }
    
} } // namespace progtech::random

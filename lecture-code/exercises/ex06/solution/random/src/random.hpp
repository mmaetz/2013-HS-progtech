#ifndef PROGTECH_RANDOM_HPP
#define PROGTECH_RANDOM_HPP

namespace progtech { namespace random 
{
    
class Generator
{
public:
    typedef unsigned result_type;
    
    Generator(result_type seed=42);
    result_type operator()();
    static result_type max();
    
private:
    typedef unsigned impl_type;
    impl_type seed_;
    
    static const impl_type a_;
    static const impl_type c_;
    static const impl_type m_;
};

} } // namespace progtech::random 

#endif // !defined PROGTECH_RANDOM_HPP

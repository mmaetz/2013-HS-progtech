#include "animal.hpp"
#include <cassert>

namespace Penna
{

// Definition of static data members
age_type Animal::bad_threshold_ = 2;
age_type Animal::maturity_age_ = 0;

void Animal::set_bad_threshold( age_type t )
{
    bad_threshold_ = t;
}
    
void Animal::set_maturity_age( age_type r )
{
    maturity_age_ = r;
}

age_type const Animal::bad_threshold()
{
    return bad_threshold_;
}

/// Default constructor: Uses all good genome.
Animal::Animal()
:   age_(0)
{
}

/// Constructor using a given genome.
Animal::Animal( const Genome& gen )
:   gen_(gen)
,   age_(0)
{
}

bool Animal::is_dead() const
{
    return age_ > maximum_age || gen_.count_bad(age_) > bad_threshold_;
}

bool Animal::is_mature() const
{
    return age_ > maturity_age_;
}
    
age_type Animal::age() const
{
    return age_;
}
	
void Animal::grow()
{
	assert( !is_dead() );
	++age_;
}

Animal Animal::give_birth() const
{
	assert( is_mature() );
	return Animal( gen_.mutate() );
}

} // end namespace Penna

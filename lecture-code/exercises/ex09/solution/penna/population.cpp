#include "population.hpp"
#include <vector>
#include <algorithm>
#include <functional>
#include <cstdlib>

using namespace std;


namespace Penna 
{

Population::Population( size_t nmax, size_t n0 )
:	list<Animal>( n0 )
,   nmax_( nmax )
{
}

void Population::simulate( size_t time )
{
    while( time-- )
        step();
}
    
class DeathPredicate
{
public:
    DeathPredicate( double probability ) : probability_(probability) {};
    bool operator()( Animal const& a ) const
    {
        return probability_ >= 1. || a.is_dead() || drand48() < probability_;
    };
    
private:
    double probability_;
};
    

void Population::step()
{
    // Age all animals
    for_each( begin(), end(), mem_fun_ref(&Animal::grow) );
    
    // Remove dead ones
    remove_if( DeathPredicate( size() / double( nmax_ ) ) );
    
    // Generate offsprings
    vector<Animal> parents;
    remove_copy_if( begin(), end(), back_inserter(parents), not1( mem_fun_ref(&Animal::is_mature) ) );
    transform( parents.begin(), parents.end(), back_inserter(*this), mem_fun_ref(&Animal::give_birth) );
}

} // end namespace Penna

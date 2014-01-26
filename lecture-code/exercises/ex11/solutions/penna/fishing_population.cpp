#include "fishing_population.hpp"
#include <vector>
#include <algorithm>
#include <functional>
#include <cstdlib>

using namespace std;


namespace Penna 
{

FishingPopulation::FishingPopulation( size_t nmax, size_t n0, size_t fstart, double frate, size_t fage )
:   Population( nmax, n0 )
,   year_( 0 )
,   fstart_( fstart )
,   frate_( frate )
,   fage_( fage )
{
}

class FishingPredicate
{
public:
    FishingPredicate( double probability, size_t minage )
    :   probability_(probability), minage_(minage) {};
    bool operator()( Animal const& a ) const
    {
        return a.age() > minage_ && (probability_ >= 1. || drand48() < probability_);
    };
    
private:
    double probability_;
    size_t minage_;
};
    
void FishingPopulation::step()
{
    // Do normal aging
    Population::step();
    
    // Fishing
    if( year_ > fstart_ )
        remove_if( FishingPredicate( frate_, fage_ ) );

    // Count years
    ++year_;
}

} // end namespace Penna

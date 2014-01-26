#ifndef FISHING_POPULATION_HPP
#define FISHING_POPULATION_HPP

#include "population.hpp"
#include <list>

namespace Penna
{

/**
 * Population of animals with fishing.
 */
class FishingPopulation : public Population
{
public:
    /**
     * Constructor.
     * @param nmax Maximum population size. Parameter N_{max} in Penna's paper.
     * @param n0 Initial population size.
     * @param fstart: Start time for fishing.
     * @param frate: Percentage of fish caught.
     * @param fage: Minimum age for removal by fishing.
     */
    FishingPopulation( std::size_t nmax, std::size_t n0, std::size_t fstart, 
                       double frate, std::size_t fage );
    
    /// Simulate one time step (year).
    void step();
    
private:
    std::size_t year_;
    std::size_t fstart_;
    double frate_;
    std::size_t fage_;
};

} // end namespace Penna

#endif // !defined FISHING_POPULATION_HPP

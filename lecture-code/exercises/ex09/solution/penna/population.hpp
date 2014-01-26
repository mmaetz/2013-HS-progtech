#ifndef POPULATION_HPP
#define POPULATION_HPP

#include "animal.hpp"
#include <list>

namespace Penna
{

/**
 * Population of animals.
 */
class Population : public std::list<Animal>
{
public:
    /**
     * Constructor.
     * @param nmax Maximum population size. Parameter N_{max} in Penna's paper.
     * @param n0 Initial population size.
     */
    Population( std::size_t nmax, std::size_t n0 );
    /// Classes with a vtable should have a virtual destructor.
    virtual ~Population() {};

    /// Simulate growth of the population for time years.
    void simulate( std::size_t time );
    /// Simulate one time step (year).
    virtual void step();

private:
    std::size_t nmax_;
};

} // end namespace Penna

#endif // !defined POPULATION_HPP

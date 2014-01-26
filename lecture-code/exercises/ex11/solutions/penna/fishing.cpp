#include "fishing_population.hpp"
#include "animal.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;
using namespace Penna;

void print_usage( const std::string& prog )
{
    cout << "Usage: echo [B] [M] [T] [R] [M1] [F] [pf] [Nmax] [N0] [num measurements] | "
         << prog << endl;
}

int main(int,const char** argv)
{
    // Seed random number generator
    srand48( 42 );

    size_t b, m, t, r, m1, f, nmax, n0, nmeas;
    double pf;
    if( !(cin >> b >> m >> t >> r >> m1 >> pf >> f >> nmax >> n0 >> nmeas) )
    {
    	print_usage(argv[0]);
    	return -1;
    }

    Genome::set_mutation_rate( m );
    Animal::set_bad_threshold( t );
    Animal::set_maturity_age ( r );

    cout << "## B=" << b << ", M=" << m << ", T=" << t << ", R=" << r
         << ", M1=" << m1 << ", pf=" << pf << ", F=" << f
         << ", Nmax=" << nmax << ", N0=" << n0 << endl;
    cout << "# time\tN" << endl;

    FishingPopulation pop( nmax, n0, m1, pf, f );
    size_t dt = b / nmeas;
    for( size_t i = 0; i < nmeas; ++i )
    {
    	pop.simulate( dt );
	
    	cout << i*dt << "\t" << pop.size() << endl;
    }

    return 0;
}

#include "population.hpp"
#include "animal.hpp"
#include <iostream>
#include <fstream>
#include <iterator>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;
using namespace Penna;

vector<double> gene_histogram(const Population& pop)
{
    vector<double> histo(Genome::number_of_genes);
    double n = pop.size();
    for( Population::const_iterator a = pop.begin(); a != pop.end(); ++a )
    {
        for( age_type i = 0; i < histo.size(); ++i )
            histo[i] += a->genome().is_bad(i) / n;
    }
    return histo;
}

void print_usage( const std::string& prog )
{
    cout << "Usage: echo [B] [M] [T] [R] [Nmax] [N0] [num measurements] | " << prog << endl;
}

int main(int,const char** argv)
{
    // Seed random number generator
    srand48( 42 );

    size_t b, m, t, r, nmax, n0, nmeas;
    if( !(cin >> b >> m >> t >> r >> nmax >> n0 >> nmeas) )
    {
        print_usage(argv[0]);
        return -1;
    }

    Genome::set_mutation_rate( m );
    Animal::set_bad_threshold( t );
    Animal::set_maturity_age ( r );

    cout << "## B=" << b << ", M=" << m << ", T=" << t << ", R=" << r
        << ", Nmax=" << nmax << ", N0=" << n0 << endl;
    cout << "# time\tN" << endl;

    Population pop( nmax, n0 );
    size_t dt = b / nmeas;
    for( size_t i = 0; i < nmeas; ++i )
    {
        pop.simulate( dt );

        cout << i*dt << "\t" << pop.size() << endl;
    }
    
    vector<double> genes = gene_histogram(pop);
    ofstream genefile("gene_histogram.dat");
    copy(genes.begin(),genes.end(),ostream_iterator<double>(genefile,"\n"));

    return 0;
}

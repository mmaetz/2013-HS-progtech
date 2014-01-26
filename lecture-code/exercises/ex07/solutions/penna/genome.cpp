#include "genome.hpp"
#include <cassert>
#include <cstdlib>
using namespace std;


namespace Penna
{
    
age_type Genome::mutation_rate_ = 2;
    
void Genome::set_mutation_rate( age_type m )
{
    mutation_rate_ = m; 
}

bool Genome::is_bad( age_type i ) const 
{ 
    assert( i < genes_.size() );
    return genes_[i]; 
}

age_type Genome::count_bad( age_type n ) const
{
    return (genes_<<(number_of_genes-n-1)).count();
}

Genome Genome::mutate() const
{
	Genome cpy( *this );
    
    // Mutate a random selection of M genes
    for( size_t i = 0; i < mutation_rate_; ++i )
        cpy.genes_.flip( static_cast<size_t>(drand48()*number_of_genes) );

	return cpy;
}

Genome::gene_type const& Genome::genes() const
{
    return genes_;
}

    
} // end namespace Penna

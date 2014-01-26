#include <iostream>
#include <stdlib.h>
#include <bitset>
#include <stdio.h>
#include <cassert>

typedef unsigned age_type;

class Genome
{
public:
    /// Up to this size bitset is a lot faster
    static const age_type number_of_genes = 
        std::numeric_limits<unsigned long>::digits;

    /// Default constructor: Initialize genes to all good.
    Genome() {};

    /// Check if i'th gene is bad.
    bool is_bad( age_type i ) const
    {
        assert( i < genes_.size() );
        return genes_[i]; 
    }
    /// Generate a copy of this, except for M flipped genes.
    Genome mutate() const
    {
        srand48(time(NULL));
        Genome cpy(*this);
        for( size_t i = 0; i < mutation_rate_; ++i )
            cpy.genes_.flip( static_cast<size_t>(drand48()*number_of_genes) );
        return cpy;
    }

private:
    typedef std::bitset<number_of_genes> gene_type;

    static const age_type mutation_rate_=10;
    gene_type genes_;
};


int main() {
    Genome G;

    std::cout <<"Genome before mutation:"<< '\t';
    for(age_type i=0;i<Genome::number_of_genes;i++)
        std::cout << G.is_bad(i);
    std::cout << std::endl;

    G=G.mutate();

    std::cout <<"Genome after mutation:"<<'\t';
    for(age_type i=0;i<Genome::number_of_genes;i++)
        std::cout << G.is_bad(i);
    std::cout << std::endl;

    G=G.mutate();

    std::cout <<"Genome after 2nd mutation:"<<'\t';
    for(age_type i=0;i<Genome::number_of_genes;i++)
        std::cout << G.is_bad(i);
    std::cout << std::endl;
}


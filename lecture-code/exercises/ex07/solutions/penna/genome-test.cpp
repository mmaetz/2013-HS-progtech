/*
 * This is the test program for genome class
 */


#include "genome.hpp"
#include <cassert>

void test(int M)
{
    Penna::Genome::set_mutation_rate(M);
    
    Penna::Genome parent_genome;
    Penna::Genome child_genome;
    
    for (std::size_t index=0; index < 1000; ++index)
    {
        child_genome = Penna::Genome(parent_genome.mutate());
        
        std::size_t bad=0;
        for (std::size_t age=0; age < Penna::Genome::number_of_genes; ++age) 
        {
            if (child_genome.is_bad(age))
                ++bad;
            assert (bad == child_genome.count_bad(age));
        }
        
        int diff = (parent_genome.genes() ^ child_genome.genes()).count();
        assert ( diff <= M && (diff%2 == M%2));
        parent_genome = child_genome;  
    }
}


int main(int agrc, char** argv)
{
    test(2);
    test(3);
    test(4);
    return 0;
}

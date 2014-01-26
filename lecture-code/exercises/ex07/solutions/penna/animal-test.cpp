/*
 * This is the test program for animal class
 */

#include "animal.hpp"
#include <cassert>


void test ()
{
    Penna::Genome genome;
    
    for (std::size_t index=0; index < 1000; ++index)
    {
        genome = genome.mutate();
        Penna::Animal animal(genome);
        
        while (!animal.is_dead()) {
            assert(genome.count_bad(animal.age()) <= Penna::Animal::bad_threshold());
            
            if (animal.is_mature()) {
                Penna::Animal child = animal.give_birth();
                assert(child.age()==0);
            }
            animal.grow();
        }
        assert(animal.age()==Penna::Animal::maximum_age+1 ||
               genome.count_bad(animal.age())==Penna::Animal::bad_threshold()+1);
        
    }
}

int main(int agrc, char** argv)
{
    
    test();
    
    return 0;
}

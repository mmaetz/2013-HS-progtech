#include <random>
#include <vector>
#include <iostream>

int main()
{
    std::mt19937 mt; // create an engine
    
    
    std::vector<int> seeds(16); // vector of seeds
    std::minstd_rand rng_initilizer(101); // LCG generator for initialization
    // fill the init vector
    for (unsigned i=0; i<seeds.size(); ++i) seeds[i] = rng_initilizer();
    
    std::seed_seq seq(seeds.begin(), seeds.end());
    mt.seed(seq);
    
    
    // create four distributions
    std::uniform_int_distribution<int>     dist1(0,10);
    std::uniform_real_distribution<double> dist2(0.,10.);
    std::exponential_distribution<double>  dist3(.6);
    std::normal_distribution<double>       dist4(3.,2.);
    
    
    // distributions are called with the engine
    // as argument to create random numbers
    std::cout << dist1(mt) << "\n";
    std::cout << dist2(mt) << "\n";
    std::cout << dist3(mt) << "\n";
    std::cout << dist4(mt) << "\n";
    
    return 0;
}

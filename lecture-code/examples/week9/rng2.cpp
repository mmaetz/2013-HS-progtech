#include <random>
#include <vector>
#include <map>
#include <iostream>
#include <iomanip>

template <class E, class D>
void print_distribution(E & rng, D & dist) {
    // compute histogram of `dist(rng)`
    std::map<int, int> hist;
    for (int n = 0; n < 10000; ++n) {
        ++hist[std::floor( dist(rng) )];
    }
    
    // print in ASCII art
    for (std::map<int, int>::const_iterator it = hist.begin();
         it != hist.end(); ++it) {
        std::cout << std::fixed << std::setprecision(1) << std::setw(2)
                  << it->first << ' ' << std::string(it->second/150, '*')
                  << '\n';
    }
}

int main()
{
    std::mt19937 mt; // create an engine
    
    
    std::vector<int> seeds(128); // vector of seeds
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
    
    
    // create random numbers:
    std::cout << "Uniform integer distribution:" << std::endl;
    print_distribution(mt, dist1);
    std::cout << std::endl;
    
    std::cout << "Uniform real distribution:" << std::endl;
    print_distribution(mt, dist2);
    std::cout << std::endl;

    std::cout << "Exponential distribution:" << std::endl;
    print_distribution(mt, dist3);
    std::cout << std::endl;

    std::cout << "Normal distribution:" << std::endl;
    print_distribution(mt, dist4);
    std::cout << std::endl;

    return 0;
}

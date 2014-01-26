#include <timer.hpp>
#include <random.hpp>

#include <iostream>

using namespace progtech;

int main() {
    
    const size_t N = 1000000000;
    
    Timer t;
    random::Generator rnd(42);
    double s(0.0);
    
    t.start();
    for (size_t n=0; n<N; ++n)
        s += static_cast<double>( rnd() ) / random::Generator::max();
    t.stop();
    
    s /= N;
    
    std::cout << "Mean of the random number engine is: " << s << "." << std::endl;
    std::cout << "Computed in " << t.duration() << " seconds." << std::endl;
}

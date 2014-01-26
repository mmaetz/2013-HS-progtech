/* Programming Techniques for Scientific Simulations, HS 2013
 * Exercise 11.1
 */
 
#include <iostream>
#include <sys/time.h>
#include <cmath>
#include <stdexcept>
#include "simpson.hpp"
#include "simpson_test_functions_macros.hpp"


template <class F>
struct type { static const bool is_callable=true; };

template <>
struct type<int> { static const bool is_callable=false; };


struct derived_function_object : public Function {
    derived_function_object() {}
    double operator()(double x) const { return FUNCTION_TO_INTEGRATE(x); }
};

struct template_function_object {
    template_function_object() {}
    inline double operator()(double x) const { return FUNCTION_TO_INTEGRATE(x); }
};

double function_to_integrate(double x) {
    return FUNCTION_TO_INTEGRATE(x);
}


// auxiliary function which should never be executed
// its presence is necessary to provide a version for the compiler to be used in the measurement function below for the case of hard-coded Simpson_call
double Simpson_integrate(int dummy, double a, double b, unsigned N) {
    throw std::logic_error("Here should the code never come!");
}


template <class F>
void measure_and_print_time(const F& f, const double a, const double b, const unsigned N, const unsigned runs, const double exact_result) {
    struct timeval t_start, t_end;
    double t_sum1(0), t_sum2(0);
    const double tolerance=1e-10;
    double result;
    
    for (unsigned r=0; r<runs; ++r) {
        gettimeofday(&t_start, NULL);
        if (type<F>::is_callable)
            result=Simpson_integrate(f,a,b,N);  // for function pointer version, template version, derived class version
        else
            result=Simpson_integrate(a,b,N);  // for hard-coded version 
        gettimeofday(&t_end, NULL);
        if (std::abs(result-exact_result)>tolerance) {
            std::cerr<<"Numerical result deviates from the exact result by "<<std::abs(result-exact_result)
                     <<" which is more than the allowed tolerance "<<tolerance
                     <<"; exact result="<<exact_result<<"; numerical result="<<result<<std::endl<<std::flush;
            throw std::runtime_error("Numerical result does not agree with exact result");
        }
        double t=t_end.tv_sec-t_start.tv_sec+(t_end.tv_usec-t_start.tv_usec)/1000000.0;
        t_sum1+=t;
        t_sum2+=t*t;
    }
    std::cout<<t_sum1/runs<<" +/- "<<std::sqrt((t_sum2-t_sum1*t_sum1/N)/(N-1.))<<std::flush;
}


int main() {
    const unsigned discretization=1024*1024*4;
    const double lower_boundary=0.0;
    const double upper_boundary=1.0;
    const unsigned n_runs=20;

    const double precise_result=INTEGRAL(upper_boundary)-INTEGRAL(lower_boundary);
    std::cout<<"# test function: "<<FUNCTION_TO_INTEGRATE_NAME<<std::endl;
    std::cout<<"# interval for integration: <"<<lower_boundary<<","<<upper_boundary
             <<">  discretized using "<<discretization<<" bins"<<std::endl;
    std::cout<<"# precise result="<<precise_result<<std::endl;
    std::cout<<"# function_nr: hard-coded version, function pointer version, template version, abstract class version"<<std::endl;

    std::cout<<FUNCTION_NUMBER<<"  ";
    // hard-coded version
    measure_and_print_time(0,lower_boundary,upper_boundary,discretization,n_runs,precise_result);
    std::cout<<"  ";
    // function pointer version version
    measure_and_print_time(function_to_integrate,lower_boundary,upper_boundary,discretization,n_runs,precise_result);
    std::cout<<"  ";
    // template version
    template_function_object tfo;
    measure_and_print_time(tfo,lower_boundary,upper_boundary,discretization,n_runs,precise_result);
    std::cout<<"  ";
    // abstract base class version
    derived_function_object dfo;
    measure_and_print_time(dfo,lower_boundary,upper_boundary,discretization,n_runs,precise_result);
    std::cout<<std::endl;
    
    return 0;
}

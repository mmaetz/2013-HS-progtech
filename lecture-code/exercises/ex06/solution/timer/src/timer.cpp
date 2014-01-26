#include "timer.hpp"

namespace progtech {

Timer::Timer() {
    gettimeofday(&tstart, NULL);
}

void Timer::start() {
    gettimeofday(&tstart, NULL);
}

void Timer::stop() {
    gettimeofday(&tend, NULL);
}

double Timer::duration() const {
    double ret = 0.;
    ret += (tend.tv_usec - tstart.tv_usec) / 1000000.0;
    ret += (tend.tv_sec - tstart.tv_sec);
    return ret;
}

} // namespace progtech

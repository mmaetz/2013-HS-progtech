#ifndef PROGTECH_TIMER_HPP
#define PROGTECH_TIMER_HPP

#include <sys/time.h>

namespace progtech {
    
class Timer {
public:
    Timer();
    void start();
    void stop();
    double duration() const;

private:
    timeval tstart, tend;
};

} // namespace progtech

#endif // !defined PROGTECH_TIMER_HPP

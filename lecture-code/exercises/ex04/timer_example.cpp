#include <iostream>
#include <sys/time.h>

int main() {

      struct timeval t;
      gettimeofday(&t, NULL);
      double t_start=t.tv_sec+(t.tv_usec/1000000.0);
      
      
      int milliseconds = 100;
      usleep(milliseconds * 1000); // sleep for 0.1 seconds
      
      
      gettimeofday(&t, NULL);
      double elapsed_time=t.tv_sec+(t.tv_usec/1000000.0)-t_start;
      
      std::cout << "time: " << elapsed_time << std::endl;

      return 0;
}

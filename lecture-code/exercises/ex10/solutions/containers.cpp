/* Programming Techniques for Scientific Simulations, HS 2013
 * Exercise 10.1
 */

#include <iostream>
#include <sys/time.h>
#include <cstdlib>
#include <cstddef>
#include <vector>
#include <list>
#include <set>
#include <iterator>
#include <utility>
#include <limits>
#include <cassert>

class Timer {
public:

  void start() {gettimeofday(&tstart, NULL);}
  void stop() {gettimeofday(&tend, NULL);}

  double duration() const {
    double ret = 0.;
    ret += (tend.tv_usec - tstart.tv_usec) / 1000000.0;
    ret += (tend.tv_sec - tstart.tv_sec);
    return ret;
  }

private:
  timeval tstart, tend;
};

typedef long test_type;

template <class container>
void fill_container(const std::size_t num_ops, container& s) {
  typename container::iterator it;

  const test_type new_ = 1;

  for(std::size_t o=0; o < num_ops; ++o) {
    it=s.begin();
    std::advance(it,std::rand()%s.size());
    it=s.insert(it,new_);
    s.erase(it);
  }  
}

int main() 
{
  const std::size_t num_ops = 4e06;

  std::cout << "#N V[s] L[s] S[s]" << std::endl;
  for(unsigned i = 4; i < 14; ++i){
      
    const std::size_t size = 1ul << i;

    test_type* array = new test_type[size];
    for(std::size_t i=0; i < size; ++i)
      array[i] = i;

    Timer t;

    std::cout << size << std::flush;

    //vector

    std::vector<test_type> vec_(array,array+size);

    t.start();
    fill_container(num_ops,vec_);
    t.stop();    

    std::cout << ' ' << t.duration() << std::flush;
        
    //list

    std::list<test_type> list_(array,array+size);

    t.start();
    fill_container(num_ops,list_);
    t.stop();    

    std::cout << ' ' << t.duration() << std::flush;
    
    // set

    std::set<test_type> set_(array,array+size);

    t.start();
    for(std::size_t o=0; o < num_ops; ++o){
      const test_type new_ = std::rand();
      std::pair<std::set<test_type>::iterator,bool> output_pair = set_.insert(new_);
      set_.erase(output_pair.first);
    }
    t.stop();

    std::cout << ' ' << t.duration() << std::flush;

    //----

    std::cout << std::endl << std::flush;

    delete[] array;

  }

  return 0;
}

// This is flexible at runtime but still fast. Mixes virtual functions and templates.
// We don't have to rewrite the derived class for another generator, but still its fast.

#include <cstdlib>
#include <vector>

typedef double result_type;

class BufferedRNG {
public:
  
  BufferedRNG() : buffer_(100000), iter_(buffer_.end()) {}
  
  result_type min() const { return 0.;}
  result_type max() const { return 1.;}

  virtual void seed(long seedval) =0;  
  
  // If the iterator points to the end of the buffer we have to fill it.
  // Else just return the precomuted value and increment the iterator.
  result_type operator() (){
    if (iter_==buffer_.end()) {
      fill_buffer(buffer_);
      iter_=buffer_.begin();
    }
    return *iter_++;
  }
  
private:
  std::vector<result_type> buffer_;
  virtual void fill_buffer(std::vector<result_type>&) =0;
  std::vector<result_type>::iterator iter_;
};


template <class Generator>
class ConcreteRNG : public BufferedRNG {
public:
  ConcreteRNG() : rng_() {}
  void seed(long seedval) { rng_.seed(seedval);}
private:
  void fill_buffer(std::vector<result_type>& buf) {
    for (std::vector<result_type>::iterator it = buf.begin(); it !=buf.end();++it)
      *it=rng_();
  }
  
  Generator rng_;
};



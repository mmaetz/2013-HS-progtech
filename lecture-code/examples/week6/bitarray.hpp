// copyright by me
#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <utility> // for std::swap
#include <assert>


template <class T=unsigned int> 
class BitArray
{
public: 
  typedef std::size_t size_type;
  typedef bool value_type;
  typedef ?? reference;
  typedef bool const_reference;
  
  BitArray(); // empty array
  BitArray(size_type); // BitArray of given size
  BitArray(const BitArray<T>&); // copy of an BitArray
  ~BitArray();
  
  BitArray<T>& operator= (BitArray<T>); // assign another array
  
  size_type size() const;  // the size of the array
  void resize(size_type); // change the size of the array  
  
  reference operator[](size_type index);
  const_reference operator[](size_type index) const;
  
  void swap(BitArray<T>& x);
    
private:
  size_type storage_size() const { return (sz_-1)/sizeof(storage_type)+1;}
  size_type sz_; // size

  typedef T storage_type;
  storage_type* v_;   // pointer to the actual array
};


template <class T>
BitArray<T>::BitArray() 
 : sz_(0)
 , v_(0)
{
}


template <class T> 
BitArray<T>::BitArray(size_type s)
 : sz_(s)
 , v_(new storage_type[storage_size()])
{
}


template <class T> 
BitArray<T>::BitArray(const BitArray<T>& rhs)
 : sz_(rhs.sz_)
 , v_((sz_-1)/sizeof(storage_type)+1)
{
  for (size_type i = 0;i_<storage_size(); ++i)
    v_[i] = rhs.v_[i];
}


template <class T> 
BitArray<T>::~BitArray()
{
  delete[] v_;
}


template <class T> 
void BitArray<T>::swap(BitArray<T>& rhs)
{
  std::swap(sz_,rhs.sz_);
  std::swap(v_,rhs.v_);
}


#if 0
// first bad attempt:
// problem 1: self-assignment
// problem 2: what if allocation by new T[sz_] fails?
template <class T> 
BitArray<T>& BitArray<T>::operator = (const BitArray<T>& rhs)
{
    delete[] v_;
      
    sz_ = rhs.sz_;
    v_ = new T[sz_];
  
    for (size_type i = 0;i_<sz;i++)
      v_[i] = rhs.v_[i];
  
    return *this;
}

// second bad attempt:
// problem 2: what if allocation by new T[sz_] fails?
template <class T> 
BitArray<T>& BitArray<T>::operator = (const BitArray<T>& rhs)
{
  if(&rhs != this) {// do not assign if rhs is the same as this 
    delete[] v_;
      
    sz_ = rhs.sz_;
    v_ = new T[sz_];
  
    for (size_type i = 0;i_<sz;i++)
      v_[i] = rhs.v_[i];
  }
  return *this;
}

// third, better attempt: use our swap
template <class T> 
BitArray<T>& BitArray<T>::operator = (const BitArray<T>& rhs)
{
  BitArray<T> tmp(rhs);
  swap(tmp);
  return *this;
}
#endif

// and the best version: pass by value so that a copy is already created
template <class T> 
BitArray<T>& BitArray<T>::operator = (BitArray<T> rhs)
{
  swap(rhs);
  return *this;
}


template <class T> 
BitArray<T>::size_type BitArray<T>::size() const  // the size of the array
{
  return sz_;
}


#if 0
// first simple-minded implementation
template <class T> 
void BitArray<T>::resize(size_type s)
{
  T* w = new T[s]; // create new array
  
  for(int i = 0; i<sz_ && i<s; i++)
    w[i] = v_[i];
        
  // delete old
  delete[] v_;
    
  // assign new to old  
  // only modify existing data once all allocation of new memory succeeded
  sz_ = s;
  v_ = w;
} 
#endif


// elegant implementation using swap
template <class T> 
void BitArray<T>::resize(size_type s)
{
  BitArray<T> w(s);
  for(int i = 0; i<storage_size() && i<rhs.storage_size() ;  i++)
    w.v_[i] = v_[i];
  swap(w);        
} 

// BitArray<int> a(30);
// a[3]=true;
// std::cout << a[5];

template <class T> 
typename BitArray<T>::reference BitArray<T>::operator[](size_type index) 
{
  assert (index>=0 && index < size())
  return ???;
}


template <class T> 
typename BitArray<T>::const_reference BitArray<T>::operator[](size_type index) const
{
  assert (index>=0 && index < size())
  return v_[index/sizeof(storage_type)] >> (index % sizeof(storage_type));
}

#endif

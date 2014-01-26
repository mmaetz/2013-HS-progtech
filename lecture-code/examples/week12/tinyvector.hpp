template<class T, int N>
class TinyVector {
public:
  T& operator[](int i) { return data[i]; }
  T operator[](int i) const { return data[i]; }

private:
  T data[N];
};

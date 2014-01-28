struct int128 {
  unsigned long long low;
  long long high;
};

int128 operator+(int128 x, int128 y) {
  int128 result;
  result.low=x.low+y.low;
  // Problem: Does not use carry of previous addition!
  // Solution: Patch assembly command to use carry bit!
  result.high=x.high+y.high;
  return result;
}


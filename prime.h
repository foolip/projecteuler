#ifndef PRIME_H_
#define PRIME_H_

#include <assert.h>

class Integers {
 public:
  explicit Integers(int start, int step)
    : current_(start) , step_(step) {
    assert(step > 0);
  }
  int current() { return current_; }
  void next() { current_ += step_; }
 private:
  int current_;
  int step_;
};

static bool isPrime(int n) {
  assert(n > 2 && n % 2 == 1);
  for (int divisor = 3; divisor * divisor <= n; divisor += 2) {
    if (n % divisor == 0)
      return false;
  }
  return true;
}

class Primes {
 public:
  Primes() : current_(3) {}
  int current() { return current_; }
  void next() {
    do {
      current_ += 2;
    } while (!isPrime(current_));
  }
 private:
  int current_;
};

#endif  // PRIME_H_

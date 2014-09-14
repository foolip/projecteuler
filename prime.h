#ifndef PRIME_H_
#define PRIME_H_

#include <assert.h>
#include <algorithm>
#include <queue>

template <typename Int>
static bool isPrime(Int n) {
  if (n < 2)
    return false;
  if (n % 2 == 0)
    return false;
  for (Int divisor = 3; divisor * divisor <= n; divisor += 2) {
    if (n % divisor == 0)
      return false;
  }
  return true;
}

template <typename Int>
class PrimesTrialDivision {
 public:
  PrimesTrialDivision() : current_(3) {}

  Int current() { return current_; }

  void next() {
    do {
      current_ += 2;
    } while (!isPrime(current_));
  }

 private:
  Int current_;
};

template <typename Int>
class Multiple {
 public:
  explicit Multiple(Int prime) : value_(prime * prime), step_(2 * prime) {}

  bool operator<(const Multiple& other) const {
    // > instead of < so that the priority_queue is reversed
    return value_ > other.value_;
  }

  Int value() const { return value_; }

  void next() { value_ += step_; }

 private:
  Int value_;
  Int step_;
};

template <typename Int>
class PrimesEratosthenes {
 public:
  PrimesEratosthenes() : current_(3) {
    multiples_.emplace(3);
  }

  Int current() const { return current_; }

  void next() {
    for (;;) {
      current_ += 2;
      const Int smallest_multiple = multiples_.top().value();
      if (current_ == smallest_multiple) {
        // current_ is composite
        assert(!isPrime(current_));
        do {
          Multiple<Int> multiple = multiples_.top();
          multiples_.pop();
          multiple.next();
          multiples_.emplace(multiple);
        } while (multiples_.top().value() == smallest_multiple);
        continue;
      } else {
        assert(current_ < smallest_multiple);
        // current_ is prime
        assert(isPrime(current_));
        multiples_.emplace(current_);
        break;
      }
    }
  }

 private:
  Int current_;
  std::priority_queue<Multiple<Int>> multiples_;
};

#endif  // PRIME_H_

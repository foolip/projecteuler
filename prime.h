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
class Marked {
  Marked(Int value, Int step) : value_(value), step_(step) {}

 public:
  explicit Marked(Int prime) : value_(prime * prime), step_(2 * prime) {}

  bool operator<(const Marked& other) const {
    // > instead of < so that the priority_queue is reversed
    return value_ > other.value_;
  }

  Int value() const { return value_; }

  Marked next() const { return Marked(value_ + step_, step_); }

 private:
  Int value_;
  Int step_;
};

template <typename Int>
class PrimesEratosthenes {
 public:
  PrimesEratosthenes() : current_(3) {
    active_marked_.emplace(3);
  }

  Int current() const { return current_; }

  void next() {
    Int n = current_;

    for (;;) {
      n += 2;

      assert(n <= active_marked_.top().value());
      assert(pending_marked_.empty() || n <= pending_marked_.front().value());

      if (active_marked_.top().value() == n) {
        // n is composite
        assert(!isPrime(n));
        do {
          active_marked_.push(active_marked_.top().next());
          active_marked_.pop();
        } while (active_marked_.top().value() == n);
      } else if (!pending_marked_.empty() &&
                 pending_marked_.front().value() == n) {
        // n is composite
        assert(!isPrime(n));
        active_marked_.push(pending_marked_.front().next());
        pending_marked_.pop();
      } else {
        // n is prime
        assert(isPrime(n));
        pending_marked_.emplace(n);
        break;
      }
    }

    current_ = n;
  }

 private:
  Int current_;
  std::priority_queue<Marked<Int>> active_marked_;
  std::queue<Marked<Int>> pending_marked_;
};

#endif  // PRIME_H_

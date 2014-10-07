#include <assert.h>
#include <iostream>
#include <vector>

class Collatz {
 public:
  explicit Collatz(size_t cache_limit);

  // Returns the number in the Collatz sequence after n.
  uint64_t next(uint64_t n) const;

  // Returns the length of the Collatz sequence starting at n.
  uint64_t length(uint64_t n) const;

 private:
  mutable std::vector<uint64_t> cache_;
};

Collatz::Collatz(size_t cache_limit) {
  assert(cache_limit > 1);
  cache_.resize(cache_limit, 0);
  cache_[1] = 1;
}

uint64_t Collatz::next(uint64_t n) const {
  assert(n > 0);

  uint64_t m;
  if (n % 2 == 0) {
    m = n / 2;
  } else {
    m = 3 * n + 1;
    // overflow check
    assert((m - 1) / 3 == n);
  }

  assert(m > 0);
  return m;
}

uint64_t Collatz::length(uint64_t n) const {
  assert(n > 0);

  const bool use_cache = n < cache_.size();

  if (use_cache) {
    uint64_t cached = cache_[n];
    if (cached) return cached;
  }

  uint64_t length_n = 1 + length(next(n));
  assert(length_n > 0);

  if (use_cache) {
    cache_[n] = length_n;
    assert(length(n) == length_n);
  }

  return length_n;
}

int main() {
  const size_t kLimit = 1000000;

  Collatz collatz(kLimit);

  uint64_t max_length = 0;
  uint64_t n_with_max_length = 0;
  for (uint64_t n = 1; n < kLimit; ++n) {
    uint64_t length = collatz.length(n);
    if (length > max_length) {
      max_length = length;
      n_with_max_length = n;
    }
  }

  std::cout << n_with_max_length << std::endl;

  return 0;
}

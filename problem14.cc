#include <assert.h>
#include <iostream>
#include <map>

class Collatz {
 public:
  Collatz();

  // Returns the number in the Collatz sequence after n.
  int64_t next(int64_t n) const;

  // Returns the length of the Collatz sequence starting at n.
  int64_t length(int64_t n) const;

 private:
  mutable std::map<int64_t, int64_t> length_cache_;
};

Collatz::Collatz() {
  length_cache_.emplace(1, 1);
}

int64_t Collatz::next(int64_t n) const {
  assert(n > 0);

  int64_t m;
  if (n % 2 == 0)
    m = n / 2;
  else
    m = 3 * n + 1;

  assert(m > 0);
  return m;
}

int64_t Collatz::length(int64_t n) const {
  assert(n > 0);

  auto cached = length_cache_.find(n);
  if (cached != length_cache_.end())
    return cached->second;

  int64_t length_n = 1 + length(next(n));
  assert(length_n > 0);

  length_cache_[n] = length_n;
  assert(length(n) == length_n);

  return length_n;
}

int main() {
  Collatz collatz;

  int64_t max_length = 0;
  int64_t n_with_max_length = 0;
  for (int64_t n = 1; n < 1000000; ++n) {
    int64_t length = collatz.length(n);
    if (length > max_length) {
      max_length = length;
      n_with_max_length = n;
    }
  }

  std::cout << n_with_max_length << std::endl;

  return 0;
}

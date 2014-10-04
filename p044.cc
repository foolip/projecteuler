#include <float.h>
#include <assert.h>
#include <math.h>
#include <stdint.h>
#include <iostream>
#include <limits>
#include <vector>

namespace {

template <typename T>
class Pentagonal {
 public:
  Pentagonal() : cache_ { 0 } {}

  T operator()(size_t n) {
    if (cache_.size() <= n) {
      size_t old_size = cache_.size();
      assert(old_size > 0);
      cache_.resize(n + 1);
      for (size_t i = old_size; i < cache_.size(); ++i) {
        cache_[i] = cache_[i - 1] + 3*static_cast<T>(i) - 2;
        assert(cache_[i] > cache_[i - 1]);
      }
    }
    return cache_[n];
  }

 private:
  std::vector<T> cache_;
};

template <typename T>
bool IsPentagonal(T x) {
  // x = (n * (3*n - 1)) / 2 => n = (sqrt(24*x + 1) + 1) / 6, so x is a
  // pentagonal number if (sqrt(24*x + 1) + 1) / 6 is an integer.
  assert(x > 0);
  assert(x <= 375299968947541); // (2^53 - 1) / 24
  double n = (sqrt(24.0*x + 1.0) + 1.0) / 6.0;
  double _;
  return modf(n, &_) == 0.0;
}

template <typename T>
T MatchingPentagonalPairDifference() {
  Pentagonal<T> p;
  // The difference between p(k) and p(j) will be a pentagonal number, so find
  // for and test pairs where the difference is a pentagonal number.
  for (size_t n = 1; n < std::numeric_limits<size_t>::max(); ++n) {
    const T diff = p(n);
    // FIXME: Increment j and k with finesse so that the diff_k_j alternates
    // around diff until either it matches or j==k.
    for (size_t j = 1; ; ++j) {
      if (p(j + 1) - p(j) > diff)
        break;
      for (size_t k = j + 1; ; ++k) {
        const T diff_k_j = p(k) - p(j);
        assert(diff_k_j > 0);
        if (diff_k_j == diff) {
          const T sum_k_j = p(k) + p(j);
          if (IsPentagonal(sum_k_j))
            return diff;
        } else if (diff_k_j > diff) {
          break;
        }
      }
    }
  }

  assert(false);
  return 0;
}

}  // namespace

int main() {
  auto d = MatchingPentagonalPairDifference<int64_t>();
  std::cout << d << std::endl;
  return 0;
}

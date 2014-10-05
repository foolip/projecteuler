#include <float.h>
#include <assert.h>
#include <math.h>
#include <stdint.h>
#include <iostream>
#include <limits>
#include <vector>

namespace {

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
  // p(n) is the nth pentagonal number.
  auto p = [] (T n) {
    assert(n > 0);
    return (n * (3*n - 1)) / 2;
  };

  // The difference between p(k) and p(j) will be a pentagonal number, so find
  // and test pairs where the difference is a pentagonal number.
  for (T n = 1; n < std::numeric_limits<T>::max(); ++n) {
    const T diff = p(n);

    // Increment either j or k so that the diff_k_j alternates around diff until
    // either it matches or j==k.
    T j = 1;
    T k = n + 1;
    for (;;) {
      assert(j < k);
      const T diff_k_j = p(k) - p(j);
      assert(diff_k_j > 0);

      if (diff_k_j == diff) {
        const T sum_k_j = p(k) + p(j);
        if (IsPentagonal(sum_k_j))
          return diff;
        j++;
        k++;
        continue;
      }

      if (diff_k_j < diff) {
        k++;
        continue;
      }

      assert(diff_k_j > diff);
      j++;
      if (j == k)
        break;
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

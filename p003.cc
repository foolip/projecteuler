#include <iostream>

namespace {

constexpr auto LargestPrimeFactor(int64_t n) {
  int64_t largest_factor = 1;
  for (int64_t factor = 2; n > 1; ++factor) {
    while (n % factor == 0) {
      largest_factor = factor;
      n /= factor;
    }
  }
  return largest_factor;
}

}  // namespace

int main() {
  constexpr auto factor = LargestPrimeFactor(600851475143);
  std::cout << factor << std::endl;
  return 0;
}

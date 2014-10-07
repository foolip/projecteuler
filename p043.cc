#include <algorithm>
#include <iostream>
#include <vector>

namespace {

int64_t SumMatchingPandigitals() {
  int64_t sum = 0;

  // A 0 to 9 pandigital number cannot start with 0, so there are 9*9! = 3265920
  // numbers to test.
  int digits[] = {1, 0, 2, 3, 4, 5, 6, 7, 8, 9};

  // Gets the integer starting at |offset| (1-index) of |length|.
  auto at = [&](size_t offset, size_t length) {
    assert(offset >= 1);
    assert(offset <= 10);
    assert(length >= 1);
    assert(offset + length <= 11);

    int64_t n = 0;
    for (size_t i = offset - 1; i < offset - 1 + length; ++i) {
      n *= 10;
      n += digits[i];
    }
    return n;
  };

  do {
    // d2 d3 d4 is divisible by 2
    if (at(4, 1) % 2 != 0) continue;
    // d3 d4 d5 is divisible by 3
    if (at(3, 3) % 3 != 0) continue;
    // d4 d5 d6 is divisible by 5
    if (at(6, 1) % 5 != 0) continue;
    // d5 d6 d7 is divisible by 7
    if (at(5, 3) % 7 != 0) continue;
    // d6 d7 d8 is divisible by 11
    if (at(6, 3) % 11 != 0) continue;
    // d7 d8 d9 is divisible by 13
    if (at(7, 3) % 13 != 0) continue;
    // d8 d9 d10 is divisible by 17
    if (at(8, 3) % 17 != 0) continue;

    // This is a matching pandigital.
    sum += at(1, 10);
  } while (std::next_permutation(std::begin(digits), std::end(digits)));

  return sum;
}

}  // namespace

int main() {
  auto sum = SumMatchingPandigitals();
  std::cout << sum << std::endl;
  return 0;
}

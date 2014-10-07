#include <algorithm>
#include <iostream>
#include <vector>

namespace {

void ToDigits(int n, std::vector<int>& digits) {
  assert(n > 0);

  digits.resize(0);
  while (n) {
    digits.push_back(n % 10);
    n /= 10;
  }
  std::reverse(digits.begin(), digits.end());
}

template <typename T>
int FromDigits(T begin, T end) {
  int product = 0;
  for (T i = begin; i != end; ++i) {
    product *= 10;
    product += *i;
  }
  return product;
}

bool IsConcatenatedProduct(const std::vector<int>& digits,
                           std::vector<int>& scratch, size_t num_digits) {
  assert(digits.size());
  assert(num_digits <= digits.size());

  const int multiplicand = FromDigits(&digits[0], &digits[num_digits]);
  size_t matched_digits = num_digits;
  for (int product = multiplicand * 2;; product += multiplicand) {
    ToDigits(product, scratch);
    for (int next_digit : scratch) {
      if (next_digit != digits[matched_digits]) return false;
      matched_digits++;
      if (matched_digits == digits.size()) return true;
      if (matched_digits > digits.size()) return false;
    }
  }
  assert(false);
}

bool IsConcatenatedProduct(const std::vector<int>& digits,
                           std::vector<int>& scratch) {
  assert(digits.size());

  for (size_t num_digits = 1; num_digits <= digits.size() / 2; ++num_digits) {
    if (IsConcatenatedProduct(digits, scratch, num_digits)) return true;
  }
  return false;
}

int LargestPandigitalConcatenatedProduct(std::vector<int>& scratch) {
  std::vector<int> digits{9, 8, 7, 6, 5, 4, 3, 2, 1};
  do {
    if (IsConcatenatedProduct(digits, scratch))
      return FromDigits(digits.begin(), digits.end());
  } while (std::prev_permutation(digits.begin(), digits.end()));

  assert(false);
  return 0;
}

}  // namespace

int main() {
  // Reusing this vector in ToDigit makes a huge difference in speed, but
  // passing it around everywhere is ugly. Use thread-local storage?
  std::vector<int> scratch;
  int answer = LargestPandigitalConcatenatedProduct(scratch);
  std::cout << answer << std::endl;
  return 0;
}

#include <iostream>

namespace {

constexpr auto SumEvenFibonacciTerms() {
  int sum = 0;
  int i = 1;
  int j = 2;
  while (j < 4000000) {
    if (j % 2 == 0) sum += j;
    int k = i + j;
    i = j;
    j = k;
  }
  return sum;
}

}  // namespace

int main() {
  constexpr auto sum = SumEvenFibonacciTerms();
  std::cout << sum << std::endl;
  return 0;
}

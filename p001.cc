#include <iostream>

namespace {

constexpr auto SumMultiples() {
  int sum = 0;
  for (int i = 1; i < 1000; ++i)
    if (i % 3 == 0 || i % 5 == 0) sum += i;
  return sum;
}

}  // namespace

int main() {
  constexpr auto sum = SumMultiples();
  std::cout << sum << std::endl;
  return 0;
}

#include <assert.h>
#include <iostream>

namespace {

int square_of_digits(int n) {
  assert(n > 0);

  int m = 0;
  while (n != 0) {
    int digit = n % 10;
    m += digit * digit;
    n /= 10;
  }

  assert(m > 0);
  return m;
}

bool arrives_at_89(int n) {
  while (n != 1 && n != 89)
    n = square_of_digits(n);
  return n == 89;
}

int count_arrives_at_89(int begin, int step, int end) {
  assert(begin > 0);
  assert(step > 0);
  assert(end > begin);

  int count = 0;
  for (int n = begin; n < end; n += step) {
    count += arrives_at_89(n);
  }
  return count;
}

}  // namespace

int main() {
  const int kLimit = 10000000;

  int answer = count_arrives_at_89(1, 1, kLimit);

  std::cout << answer << std::endl;

  return 0;
}

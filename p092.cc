#include <assert.h>
#include <future>
#include <iostream>
#include <thread>
#include <vector>

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

  unsigned threads = std::thread::hardware_concurrency();
  assert(threads > 0);

  std::vector<std::future<int>> futures;
  for (int i = 1; i <= static_cast<int>(threads); ++i) {
    futures.push_back(std::async(std::launch::async, count_arrives_at_89, i, threads, kLimit));
  }

  int answer = 0;
  for (std::future<int>& f : futures) {
    answer += f.get();
  }

  std::cout << answer << std::endl;

  return 0;
}

#include <assert.h>
#include <stdint.h>
#include <algorithm>
#include <iostream>
#include <vector>

#include "prime.h"

namespace {

std::vector<uint64_t> primes_to(uint64_t limit) {
  std::vector<uint64_t> result;
  result.push_back(2);
  PrimesEratosthenes<uint64_t> primes;
  while (primes.current() < limit) {
    result.push_back(primes.current());
    primes.next();
  }
  return result;
}

size_t max_sequence_length(const std::vector<uint64_t>& primes) {
  const uint64_t max_prime = primes.back();
  size_t length = 0;
  uint64_t sum = 0;
  for (uint64_t prime : primes) {
    sum += prime;
    if (sum > max_prime)
      return length;
    length++;
  }
  assert(false);
  return 0;
}

uint64_t find_prime_sum(const std::vector<uint64_t>& primes, size_t length) {
  assert(length <= primes.size());

  size_t begin = 0;
  size_t end = length;

  uint64_t sum = 0;
  for (size_t i = begin; i != end; ++i) {
    sum += primes[i];
  }

  const uint64_t max_prime = primes.back();
  assert(sum <= max_prime);

  do {
    if (std::binary_search(primes.begin(), primes.end(), sum)) {
      assert(isPrime(sum));
      return sum;
    }
    assert(end < primes.size());
    assert(end - begin == length);
    sum -= primes[begin++];
    sum += primes[end++];
  } while (sum <= max_prime);

  return 0;
}

}  // namespace

int main() {
  const std::vector<uint64_t> primes = primes_to(1000000);
  assert(std::is_sorted(primes.begin(), primes.end()));

  for (size_t length = max_sequence_length(primes); length > 0; --length) {
    if (uint64_t sum = find_prime_sum(primes, length)) {
      std::cout << sum << " (length " << length << ")" << std::endl;
      return 0;
    }
  }

  assert(false);
  return -1;
}

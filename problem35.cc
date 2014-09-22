#include <assert.h>
#include <stdint.h>
#include <iostream>
#include <vector>

#include "prime.h"

namespace {

std::vector<bool> is_prime_to(size_t limit) {
  std::vector<bool> result;
  result.resize(limit, false);
  result[2] = true;
  for (PrimesEratosthenes<size_t> primes;
       primes.current() < limit; primes.next()) {
    result[primes.current()] = true;
  }
  return result;
}

size_t count_digits(size_t n) {
  size_t d = 0;
  while (n) {
    n /= 10;
    d++;
  }
  return d;
}

size_t pow10(size_t n) {
  size_t p = 1;
  while (n) {
    n--;
    p *= 10;
  }
  return p;
}

size_t rotate(size_t n, size_t p) {
  return p * (n % 10) + (n / 10);
}

}  // namespace

int main() {
  const size_t kLimit = 1000000;

  const std::vector<bool> is_prime = is_prime_to(kLimit);

  size_t answer = 0;
  for (size_t n = 2; n < kLimit; ++n) {
    if (is_prime[n]) {
      size_t digits = count_digits(n);
      size_t power = pow10(digits - 1);
      size_t rotation = n;
      bool all_rotations_are_prime = true;
      for (size_t i = 1; i < digits; ++i) {
        rotation = rotate(rotation, power);
        if (!is_prime[rotation]) {
          all_rotations_are_prime = false;
          break;
        }
      }
      if (all_rotations_are_prime)
        answer++;
    }
  }

  std::cout << answer << std::endl;
}

#include <stdint.h>
#include <iostream>

#include "prime.h"

int main() {
  uint64_t sum = 2;
  PrimesEratosthenes<uint64_t> primes;
  while (primes.current() < 2000000) {
    sum += primes.current();
    primes.next();
  }
  std::cout << sum << std::endl;
  return 0;
}

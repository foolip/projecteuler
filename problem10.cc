#include <stdio.h>
#include <stdint.h>

#include "prime.h"

int main() {
  uint64_t sum = 2;
  for (Primes primes; primes.current() < 2000000; primes.next()) {
    sum += static_cast<uint64_t>(primes.current());
  }
  printf("%lld\n", sum);
  return 0;
}

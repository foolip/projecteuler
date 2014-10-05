import Data.List
import Data.Numbers.Primes

distinctPrimeFactors :: Integral a => a -> a
distinctPrimeFactors = genericLength . group . primeFactors

findConsecutive :: Integral a => a -> a
findConsecutive terms = find 1
  where
    find n = if all (\n -> distinctPrimeFactors n == terms) [n..n+terms-1]
             then n
             else find (n + 1)

answer = findConsecutive 4

main = print answer

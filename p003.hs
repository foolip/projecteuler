import Data.Numbers.Primes

answer = last $ primeFactors 600851475143

main = print answer

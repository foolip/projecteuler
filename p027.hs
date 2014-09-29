import Data.Numbers.Primes

primeProducers :: Integral a => [(a, a)] -> a -> [(a, a)]
primeProducers pairs n = filter (isPrime . (\(a, b) -> n*n + a*n + b)) pairs

maxPrimeProducer :: Integral a => (a, a)
maxPrimeProducer = reduce candidates 0
  where
    reduce pairs n = let producers = primeProducers pairs n
                     in if null producers
                        then head pairs
                        else reduce producers (n + 1)
    candidates = [(a, b) | a<-[-1000..1000], b<-[-1000..1000]]

answer = (\(a, b) -> a*b) maxPrimeProducer

main = print answer

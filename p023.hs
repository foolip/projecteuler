import Data.List
import Data.Numbers.Primes

-- http://mathworld.wolfram.com/DivisorFunction.html#eqn14
sumProperDivisors :: Integral a => a -> a
sumProperDivisors n = (div numerator denominator) - n
  where
    factors = map (\x -> (head x, length x)) $ group $ primeFactors n
    numerator = product $ map (\(p, a) -> p^(a + 1) - 1) factors
    denominator = product $ map (\(p, a) -> p - 1) factors

isAbundant :: Integral a => a -> Bool
isAbundant n = sumProperDivisors n > n

abundants :: Integral a => [a]
abundants = filter isAbundant [1..28123]

sums :: Integral a => [a] -> a -> [a]
sums terms limit = concatMap sums2 (tails terms)
  where
    sums2 [] = []
    sums2 (x:xs) = takeWhile (<=limit) (map (x+) xs)

abundantSums :: Integral a => [a]
abundantSums = sums abundants 28123

answer = length $ nub $ sort $ abundantSums

main = print answer

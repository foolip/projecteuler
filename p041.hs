import Data.List
import Data.Numbers.Primes

pandigitals :: [Int]
pandigitals = concatMap pan [9,8..1]
  where
    toint = foldl1 (\acc d -> 10*acc + d)
    pan n = (reverse . sort . (map toint) . permutations) [1..n]

answer = head $ filter isPrime pandigitals

main = print answer

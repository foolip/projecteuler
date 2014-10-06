import Data.Function
import Data.List
import Data.Maybe
import Data.Numbers.Primes
import Data.Tuple

fourDigitPrimes :: Integral a => [a]
fourDigitPrimes = takeWhile (<10000) $ dropWhile (<1000) primes

primeGroups = filter ((>=3) . length) groups
  where
    normalize = sort . show
    sorted = sortBy (compare `on` normalize) fourDigitPrimes
    groups = groupBy ((==) `on` normalize) sorted

arithmeticSequences :: Integral a => [a] -> [[a]]
arithmeticSequences = seqs3 . sort
  where
    seqs1 (x1:x2:xs) = Just (x1 : x2 : find (x2 + diff) xs)
      where
        diff = x2 - x1
        find next [] = []
        find next (x:xs)
          | x == next = x : find (next + diff) xs
          | otherwise = find next xs
    seqs1 xs = Nothing
    seqs2 (x:xs) = catMaybes $ map (\tail -> seqs1 (x : tail)) (tails xs)
    seqs2 [] = []
    seqs3 xs = concatMap seqs2 (tails xs)

primeSequences = concatMap arithmeticSequences primeGroups

candidateSequences = filter (/=[1487,4817,8147]) primeSequences

longestSequence = maximumBy (compare `on` length) candidateSequences

answer = read (concatMap show longestSequence) :: Int

main = print answer

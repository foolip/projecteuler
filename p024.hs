import Data.List

fromDigits :: Integral a => [a] -> a
fromDigits = foldl1 (\acc x -> 10*acc + x)

sortedPermutations :: Integral a => [a]
sortedPermutations = sort . map fromDigits . permutations $ [0..9]

answer = sortedPermutations !! 999999

main = print answer

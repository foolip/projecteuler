import Data.Array

factorial :: Int -> Int
factorial n = fac ! n
  where
    fac = array (0,9) [(n, product [2..n]) | n <- [0..9]]

digits :: Int -> [Int]
digits 0 = []
digits n = rem n 10 : digits (quot n 10)

sumFactorialDigits :: Int -> Int
sumFactorialDigits = sum . (map factorial) . digits

isCurious :: Int -> Bool
isCurious n = n == sumFactorialDigits n

-- Note: this seems like a pessimistic upper limit, because two digits less
-- still produces the correct answer.
maxDigits :: Int
maxDigits = (head $ filter (\n -> 10^(n-1) > n*(factorial 9)) [1..]) - 1

curious = filter isCurious [3..(10^maxDigits)-1]

answer = sum curious

main = print answer

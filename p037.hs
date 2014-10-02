import Data.Numbers.Primes

pow10 :: Integral a => [a]
pow10 = [10^n | n <- [1..]]

-- 12345 -> [5, 45, 345, 2345]
truncl :: Integral a => a -> [a]
truncl n = takeWhile (<n) $ map (rem n) pow10

-- 12345 -> [1234, 123, 12, 1]
truncr :: Integral a => a -> [a]
truncr n = takeWhile (>0) $ map (quot n) pow10

isTruncatable :: Integral a => a -> Bool
isTruncatable n = (all isPrime (truncl n)) && (all isPrime (truncr n))

truncatables = take 11 (filter isTruncatable (dropWhile (<10) primes))

answer = sum truncatables

main = print answer

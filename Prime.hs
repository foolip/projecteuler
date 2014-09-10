module Prime (
  isPrime,
  sieveEratosthenes
) where

maybePrimes :: Integral a => [a]
maybePrimes = pm1 [6,12..] where pm1 (x:xs) = x - 1 : x + 1 : pm1 xs

isPrime :: Integral a => a -> Bool
isPrime 2 = True
isPrime 3 = True
isPrime n
  | n `mod` 2 == 0 = False
  | n `mod` 3 == 0 = False
  | otherwise      = not $ any (\div -> n `mod` div == 0) $ takeWhile (<=limit) maybePrimes
  where limit = 1 + (floor $ sqrt $ fromIntegral n)

merge :: Integral a => [a] -> [a] -> [a]
merge xxs@(x:xs) yys@(y:ys)
  | x < y = x : merge xs yys
  | x == y = x : merge xs ys
  | x > y = y : merge xxs ys

sieveEratosthenes :: Integral a => [a]
sieveEratosthenes = 2 : sieve 3 [4,6..]
  where sieve n marked@(m:ms)
          | n < m = n : sieve (n + 2) (merge marked [2*n,3*n..])
          | n == m = sieve (n + 2) ms
          | n > m = sieve n ms

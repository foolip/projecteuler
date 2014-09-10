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

answer = sum $ filter isPrime [2..2000000]

main = print answer

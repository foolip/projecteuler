import Data.List (group)

-- the nth triangle number is (n * (1 + n)) / 2
triangle :: Integral a => a -> (a, a)
triangle n = if rem n 2 == 0
             then (quot n 2, n + 1)
             else (n, quot (n + 1) 2)

factorize :: Integral a => a -> [a]
factorize n = factors n 2
  where
    factors 1 d = []
    factors n d = if rem n d == 0
                  then d : factors (quot n d) d
                  else factors n (d + 1)

merge :: Ord a => [a] -> [a] -> [a]
merge xs [] = xs
merge [] xs = xs
merge xxs@(x:xs) yys@(y:ys)
  | x <= y = x : merge xs yys
  | x > y  = y : merge xxs ys

factorize2 :: (Integral a) => (a, a) -> [a]
factorize2 (n, m) = merge (factorize n) (factorize m)

-- http://mathschallenge.net/library/number/number_of_divisors
divisors2 :: Integral a => (a, a) -> Int
divisors2 nm = product $ map (succ . length) $ (group . factorize2) nm

answer = n * m
  where (n, m) = head $ filter ((>500) . divisors2) $ map triangle [1..]

main = print answer

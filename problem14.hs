import Data.Function (on)
import Data.List (maximumBy)

collatzNext :: Integral a => a -> a
collatzNext n
  | mod n 2 == 0 = div n 2
  | otherwise    = 3*n + 1

collatzLength :: Integral a => a -> a
collatzLength 1 = 1
collatzLength n = 1 + collatzLength (collatzNext n)

collatzLongest :: Integral a => [a] -> (a, a)
collatzLongest [] = (0, 0)
collatzLongest (x:xs) = if xLength > snd xsLongest then (x, xLength) else xsLongest
  where
    xLength = collatzLength x
    xsLongest = collatzLongest xs

answer = fst $ collatzLongest [1..999999]

main = print answer

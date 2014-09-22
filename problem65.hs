import Data.List
import Data.Ratio

continuedFraction :: Integral a => [a] -> Ratio a
continuedFraction (x:xs) = if null xs
                           then x % 1
                           else (x % 1) + (1 / (continuedFraction xs))

e :: Integral a => Int -> Ratio a
e k = continuedFraction (take k terms)
  where
    terms = 2 : concatMap (\k -> [1,2*k,1]) [1..]

digitSum :: Integral a => a -> a
digitSum 0 = 0
digitSum n = (mod n 10) + digitSum (div n 10)

answer = digitSum $ numerator $ e 100

main = print answer

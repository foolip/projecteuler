import Data.List
import Data.Ratio

resilience :: Integral a => a -> Ratio a
resilience d = (genericLength resilientFractions) % (d - 1)
  where
    fractions = map (%d) [1..d-1]
    resilientFractions = filter (\f -> denominator f == d) fractions

answer = head $ filter (\d -> (resilience d) < (15499 % 94744)) [2..]

main = print answer

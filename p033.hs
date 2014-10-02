import Data.List;
import Data.Ratio;

digits :: Integral a => a -> [a]
digits 0 = []
digits n = let (d, m) = divMod n 10
           in m : digits d

commonDigits :: Integral a => a -> a -> [a]
commonDigits m n = nub $ sort $ intersect (digits m) (digits n)

removeDigit :: Integral a => a -> a -> a
removeDigit d n = foldr1 (\d acc -> d + 10*acc) ds
  where
    ds = filter (/=d) (digits n)

isCurious :: Integral a => (a, a) -> Bool
isCurious (num, denom) = if null common
                         then False
                         else any (\c -> ((removeDigit c num) % (removeDigit c denom)) == ratio) common
  where
    ratio = num % denom
    common = commonDigits num denom

twoDigitNumbers :: Integral a => [a]
twoDigitNumbers = [n | n <- [12..98], mod n 10 /= 0, mod n 10 /= div n 10]

twoDigitFractions :: Integral a => [(a, a)]
twoDigitFractions = [(num, denom) | num <- twoDigitNumbers, denom <- twoDigitNumbers, num < denom]

curiousFractions = filter isCurious twoDigitFractions

curiousRatios = map (\(n, d) -> n % d) curiousFractions

answer = denominator $ foldr1 (*) curiousRatios

main = print answer

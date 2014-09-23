import Data.Char

format :: Int -> String
format 1 = "one"
format 2 = "two"
format 3 = "three"
format 4 = "four"
format 5 = "five"
format 6 = "six"
format 7 = "seven"
format 8 = "eight"
format 9 = "nine"
format 10 = "ten"
format 11 = "eleven"
format 12 = "twelve"
format 13 = "thirteen"
format 14 = "fourteen"
format 15 = "fifteen"
format 16 = "sixteen"
format 17 = "seventeen"
format 18 = "eighteen"
format 19 = "nineteen"
format 20 = "twenty"
format 30 = "thirty"
format 40 = "forty"
format 50 = "fifty"
format 60 = "sixty"
format 70 = "seventy"
format 80 = "eighty"
format 90 = "ninety"
format n
  | n > 20 && n < 100 = format (10 * (div n 10)) ++ "-" ++ format (mod n 10)
  | n >= 100 && n < 1000 = let (h, t) = divMod n 100
                               hundreds = (format h) ++ " hundred"
                           in if t == 0
                              then hundreds
                              else hundreds ++ " and " ++ (format t)
format 1000 = "one thousand"

letters :: String -> Int
letters = length . filter isLetter

answer = sum $ map (letters . format) [1..1000]

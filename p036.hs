digitsBase :: Int -> Int -> [Int]
digitsBase base 0 = []
digitsBase base n = mod n base : digitsBase base (div n base)

isPalindromeBase :: Int -> Int -> Bool
isPalindromeBase base n = digits == reverse digits
  where
    digits = digitsBase base n

isDoubleBasePalindrome :: Int -> Bool
isDoubleBasePalindrome n = isPalindromeBase 2 n && isPalindromeBase 10 n

answer = sum $ filter isDoubleBasePalindrome [1..999999]

main = print answer

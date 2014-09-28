isPalindrome :: Show a => a -> Bool
isPalindrome n = show n == reverse (show n)

products = [a*b | a <- [100..999], b <- [a..999]]

answer = maximum $ filter isPalindrome products

main = print answer

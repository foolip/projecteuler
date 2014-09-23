import Data.List

terms = [a^b | a <- [2..100], b <- [2..100]]

answer = length . group . sort $ terms

main = print answer

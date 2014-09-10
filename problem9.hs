isPythagoreanTriplet (a, b, c) = a*a + b*b == c*c

candidates = [(a, b, 1000-a-b) | a <- [1..998], b <- [a+1..999-a]]

triplet = head $ filter isPythagoreanTriplet candidates

answer = (\(a, b, c) -> a * b * c) triplet

main = print answer

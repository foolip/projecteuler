properDivisors :: Int -> [Int]
properDivisors n = filter (\x -> n `mod` x == 0) [1..n-1]

d :: Int -> Int
d = sum . properDivisors

isAmicable :: Int -> Bool
isAmicable a = a /= b && d b == a
  where
    b = d a

answer = sum $ filter isAmicable [1..9999]

main = print answer

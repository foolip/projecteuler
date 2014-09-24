sumOfDiagonals :: Int -> Int
sumOfDiagonals 1 = 1
sumOfDiagonals n | odd n = 4*n*n - 6*n + 6 + sumOfDiagonals (n - 2)

answer = sumOfDiagonals 1001

main = print answer

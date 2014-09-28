sumOfSquares = sum $ map (^2) [1..100]

squareOfSums = (sum [1..100]) ^ 2

answer = squareOfSums - sumOfSquares

main = print answer

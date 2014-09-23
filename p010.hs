import Prime

answer = sum $ filter isPrime [2..2000000]

main = print answer

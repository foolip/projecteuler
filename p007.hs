import Prime

primeAt n = (filter isPrime [2..]) !! (n - 1)

answer = primeAt 10001

main = print answer

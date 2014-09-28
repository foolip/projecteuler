fibonacci :: Integral a => [a]
fibonacci = fib 1 2
  where
    fib n m = n : fib m (n + m)

answer = sum . takeWhile (<=4000000) . filter even $ fibonacci

main = print answer

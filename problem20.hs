factorial :: (Integral a) => a -> a
factorial 1 = 1
factorial n = n * factorial (n - 1)

digitSum :: (Integral a) => a -> a
digitSum 0 = 0
digitSum n = (mod n 10) + digitSum (div n 10)

answer = digitSum $ factorial 100

main = print answer

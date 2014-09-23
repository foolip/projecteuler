digitSum :: (Integral a) => a -> a
digitSum 0 = 0
digitSum n = (mod n 10) + digitSum (div n 10)

answer = digitSum $ 2^1000

main = print answer

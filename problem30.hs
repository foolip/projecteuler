digits :: Integral a => a -> [a]
digits 0 = []
digits x = (mod x 10) : digits (div x 10)

sumNthPower :: Integral a => a -> a -> a
sumNthPower n x = sum $ map (^n) $ digits x

sum4thPower = sumNthPower 4
sum5thPower = sumNthPower 5

nines :: Integral a => a -> a
nines n | n > 0 = 10 ^ n - 1

limit = head $ filter (\n -> n > sum5thPower n) (map nines [1..])

answer = sum $ filter (\n -> n == sum5thPower n) [2..limit]

main = print answer

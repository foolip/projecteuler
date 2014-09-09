digits :: Integral a => a -> [a]
digits 0 = []
digits x = (mod x 10) : digits (div x 10)

-- The digits of the Champernowne constant as a list
c10 :: [Int]
c10 = concatMap (reverse . digits) [1..]

d :: Int -> Int
d n = c10 !! (n - 1)

ns = map (10^) [0..6]

answer = product $ map d ns

import Data.List

triangles :: Integral a => [a]
triangles = [div (n * (n + 1)) 2 | n <- [1..]]

pentagonals :: Integral a => [a]
pentagonals = [div (n * (3*n - 1)) 2 | n <- [1..]]

hexagonals :: Integral a => [a]
hexagonals = [n * (2*n - 1) | n <- [1..]]

intersectSorted :: Integral a => [a] -> [a] -> [a]
intersectSorted (x:xs) (y:ys)
  | x < y = intersectSorted xs (y:ys)
  | x > y = intersectSorted (x:xs) ys
  | x == y = x : intersectSorted xs ys

intersection = foldr1 intersectSorted [triangles, pentagonals, hexagonals]

answer = head $ dropWhile (<=40755) intersection

main = print answer

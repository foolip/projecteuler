import System.IO

-- Split string by newlines and spaces
toTriangle :: String -> [[Int]]
toTriangle s = map (map read . words) (lines s)

-- Take the maximum of each pair. The output is shorter by one element.
maxPairs :: Ord a => [a] -> [a]
maxPairs row = zipWith max row (tail row)

-- Find the maximum path by folding from the bottom, for each step generating a
-- maximum for each entry in the row. When done, the only entry is the answer.
maxPath top bottom = zipWith (+) top (maxPairs bottom)

main = do
  input <- readFile "problem67.txt"
  let triangle = toTriangle input
      answer = head $ foldr1 maxPath triangle
  print answer

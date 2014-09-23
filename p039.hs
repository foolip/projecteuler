import Data.List
import Data.Function

rightAngleTriangles :: Int -> [(Int, Int, Int)]
rightAngleTriangles p = filter isRightAngle triangles
  where
    triangles = [(a, b, p-a-b) | a <- [1..p-2], b <- [a+1..p-a-1]]
    isRightAngle (a, b, c) = a*a + b*b == c*c

answer = maximumBy (compare `on` (length . rightAngleTriangles)) [3..1000]

main = print answer

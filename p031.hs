-- Count solutions to 1a + 2b + 5c + 10d + 20e + 50f + 100g + 200h = 200,
-- where a through h are non-negative integers. Similar to:
-- http://en.wikipedia.org/wiki/Euclidean_algorithm#Linear_Diophantine_equations
-- http://en.wikipedia.org/wiki/Knapsack_problem

countSolutions :: Integral a => [a] -> a -> a
countSolutions [] 0 = 1
countSolutions [] sum = 0
countSolutions (1:[]) sum = 1
countSolutions (t:ts) sum' = sum solutions
  where
    subSums = [0,t..sum']
    solutions = map (\subSum -> countSolutions ts (sum' - subSum)) subSums

answer = countSolutions [200, 100, 50, 20, 10, 5, 2, 1] 200

main = print answer

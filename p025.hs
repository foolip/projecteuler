fiblist :: (Integral a) => a -> a -> [a]
fiblist a b = a : fiblist b (a + b)

indexedfib = zip [1..] $ fiblist 1 1

findfib pred = head $ filter (\(term, value) -> pred value) indexedfib

answer = fst $ findfib (>=10^999)

main = print answer

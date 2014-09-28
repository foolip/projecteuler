import Data.List

arithmeticSum :: Integral a => a -> a -> a -> a
arithmeticSum start step stop = (terms * (start + last)) `div` 2
  where
    terms = 1 + ((stop - start) `div` step)
    last = start + (terms - 1) * step

multiplesSum :: Integral a => a -> a
multiplesSum n = arithmeticSum n n 999

answer = multiplesSum 3 + multiplesSum 5 - multiplesSum 15

main = print answer

import Data.Function
import Data.List
import qualified Data.Map as Map
import Data.Maybe

recurringLength :: Integral a => a -> a
recurringLength d = step 1 10 Map.empty
  where
    step pos carry cache
      | carry == 0 = 0
      | otherwise = let qr = quotRem carry d
                        prevPos = Map.lookup (carry, qr) cache
                    in if isJust prevPos
                       then pos - (fromJust prevPos)
                       else step (pos + 1) (10 * (snd qr)) (Map.insert (carry, qr) pos cache)

answer = maximumBy (compare `on` recurringLength) [2..999]

main = print answer

import Data.Char
import Data.List
import Data.List.Split

readNames :: String -> [String]
readNames = wordsBy (not . isLetter)

alphabeticalValue :: String -> Int
alphabeticalValue = sum . map (\c -> ord c - ord 'A' + 1)

main = do
  input <- readFile "p022_names.txt"
  let names = readNames input
      sortedNames = sort names
      answer = sum $ zipWith (*) [1..] (map alphabeticalValue sortedNames)
  print answer

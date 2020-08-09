{-
---Indexed Capitalization---
Given a string and an array of integers representing indices, 
capitalize all letters at the given indices.

For example:

capitalize("abcdef",[1,2,5]) = "aBCdeF"
capitalize("abcdef",[1,2,5,100]) = "aBCdeF". There is no index 100.
The input will be a lowercase string with no spaces and an array of digits.

Good luck!
-}

import           Data.Char

main = print $ capitalize "abcdef" [1, 2, 5, 100]

capitalize :: String -> [Int] -> [Char]
capitalize s ns =
  zipWith (\n c -> if n `elem` ns then toUpper c else c) [0 ..] s
{-capitalize s ns =
  [ if x `elem` ns then toUpper (s !! x) else s !! x
  | x <- [0 .. length s - 1]
  ]
  -}

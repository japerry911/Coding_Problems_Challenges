{-
---Alternate Case---
Write function alternateCase which switch every letter in string from 
upper to lower and from lower to upper. E.g: Hello World -> hELLO wORLD
-}

import           Data.Char

main = print $ alternateCase "Hello World"

alternateCase :: String -> String
alternateCase s = execute s ""

execute :: String -> String -> String
execute (c : is) rs
  | null is = if isLower c
    then rs ++ [toUpper c]
    else if isUpper c then rs ++ [toLower c] else rs ++ [c]
  | isLower c = execute is (rs ++ [toUpper c])
  | isUpper c = execute is (rs ++ [toLower c])
  | otherwise = execute is (rs ++ [c])


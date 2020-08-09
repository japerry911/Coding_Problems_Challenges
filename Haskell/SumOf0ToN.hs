{-
---Sum of 0 to N---
We want to generate a function that computes the series starting
from 0 and ending until the given number.

Example:
Input:

> 6
Output:

0+1+2+3+4+5+6 = 21

Input:

> -15
Output:

-15<0

Input:

> 0
Output:

0=0
-}

main = print $ sequenceSum 6

sequenceSum :: Int -> String
sequenceSum n
  | n > 0
  = concat [ if x == n then show x else show x ++ "+" | x <- [0 .. n] ]
    ++ " = "
    ++ show (sum [0 .. n])
  | n < 0
  = show n ++ " < 0"
  | otherwise
  = "0 = 0"

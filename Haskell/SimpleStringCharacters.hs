{-
---Simple String Characters---
In this Kata, you will be given a string and your task will be to return a 
list of ints detailing the count of uppercase letters, lowercase, numbers and 
special characters, as follows.

Solve("*'&ABCDabcde12345") = [4,5,5,3]. 
--the order is: uppercase letters, lowercase, numbers and special characters.
More examples in the test cases.
-}

import           Data.Char                      ( isUpper
                                                , isLower
                                                , isDigit
                                                , isAlphaNum
                                                )

main = print $ solve "*'&ABCDabcde12345"

solve :: [Char] -> [Int]
solve ss =
  [ length (filter isUpper ss)
  , length (filter isLower ss)
  , length (filter isDigit ss)
  , length (filter (not . isAlphaNum) ss)
  ]

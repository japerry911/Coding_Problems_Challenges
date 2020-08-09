{-
---Wave---
	In this simple Kata your task is to create a function that turns a 
    string into a Mexican Wave. You will be passed a string and you must 
    return that string in an array where an uppercase letter is a person 
    standing up.
Rules
 	1.  The input string will always be lower case but maybe empty.
2.  If the character in the string is whitespace then pass over it as if 
    it was an empty seat.
Example
wave("hello") => []string{"Hello", "hEllo", "heLlo", "helLo", "hellO"}
-}

import           Data.Char

--main = print $ wave "hello"
main = print $ wave "this is a few words"

wave :: String -> [String]
wave s =
  [ makeEleUppercase x s | x <- [1 .. length s], isAlpha (s !! (x - 1)) ]

makeEleUppercase :: Int -> String -> String
makeEleUppercase d s =
  take (d - 1) s ++ [toUpper (last (take d s))] ++ drop d s

{-wave :: String -> [String]
wave s = [ makeEleUppercase x s | x <- [1 .. alphaLength] ]
  where alphaLength = calcLength s

calcLength :: String -> Int
calcLength (c : s) | null s    = 0
                   | isAlpha c = 1 + calcLength s
                   | isSpace c = 0 + calcLength s
                   | otherwise = 0

makeEleUppercase :: Int -> String -> String
makeEleUppercase d s =
  take (d - 1) s ++ [toUpper (last (take d s))] ++ drop d s-}

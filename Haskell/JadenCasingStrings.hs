{-
---Jaden Casing Strings---
Jaden Smith, the son of Will Smith, is the star of films such as 
The Karate Kid (2010) and After Earth (2013). Jaden is also known 
for some of his philosophy that he delivers via Twitter. When writing 
on Twitter, he is known for almost always capitalizing every word. For 
simplicity, you'll have to capitalize each word, check out how contractions 
are expected to be in the example below.

Your task is to convert strings to how they would be written by Jaden Smith. 
The strings are actual quotes from Jaden Smith, but they are not capitalized 
in the same way he originally typed them.

Example:

Not Jaden-Cased: "How can mirrors be real if our eyes aren't real"
Jaden-Cased:     "How Can Mirrors Be Real If Our Eyes Aren't Real"
-}

import           Data.Char

main = print $ toJadenCase "How can mirrors be real if our eyes aren't real"

toJadenCase :: String -> String
toJadenCase = unwords . map firstCap . words
 where
  firstCap (x : xs) = toUpper x : xs
  firstCap []       = []

{-toJadenCase :: String -> String
toJadenCase (c1 : s1) = toUpper c1 : convert s1
 where
  convert [] = []
  convert (c : s) | isSpace c = c : convert (capitalize s)
                  | null s    = [c]
                  | otherwise = c : convert s

capitalize :: String -> String
capitalize (c : s) = toUpper c : s-}

-- Failed below:
{-toJadenCase :: String -> String
toJadenCase (c : s) | isSpace c = c : toJadenCase (capitalize s)
                    | null s    = [c]
                    | otherwise = c : toJadenCase s

capitalize :: String -> String
capitalize (c : s) = toUpper c : s-}

{-toJadenCase :: String -> String
toJadenCase (head : tail) = toUpper head : lowered tail
 where
  lowered []            = []
  lowered (head : tail) = toUpper head : lowered tail-}

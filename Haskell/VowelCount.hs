{-
---Vowel Count---
Return the number (count) of vowels in the given string.

We will consider a, e, i, o, u as vowels for this Kata (but not y).

The input string will only consist of lower case letters and/or spaces.
-}

main = print $ getCount "abracadabra"

getCount :: String -> Int
getCount s = length [ c | c <- s, c `elem` vowels ]
  where vowels = ['a', 'e', 'i', 'o', 'u']

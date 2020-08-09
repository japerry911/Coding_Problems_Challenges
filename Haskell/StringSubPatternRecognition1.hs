{-
---String SubPattern Recognition 1---
}In this kata you need to build a function to return either 
true/True or false/False if a string can be seen as the repetition 
    of a simpler/shorter subpattern or not.

For example:

hasSubpattern "a" == False -- no repeated pattern
hasSubpattern "aaaa" == True -- created repeating "a"
hasSubpattern "abcd" == False -- no repeated pattern
hasSubpattern "abababab" == True -- created repeating "ab"
hasSubpattern "ababababa" == False -- cannot be entirely reproduced 
repeating a pattern
Strings will never be empty and can be composed of any character 
(just consider upper- and lowercase letters as different entities) 
and can be pretty long (keep an eye on performances!).

If you liked it, go for the next kata of the series!
-}

import           Data.List

main = print $ hasSubpattern "MMMMMMMMM"
--main = print $ findPattern "123a123a123a" (length "123a123a123a") ""
--main = print $ findPattern "abcdabcabcd" ""
--main = print $ 'a' == 'A'
--main = print $ checkForPattern "abcdabcabcd" (findPattern "abcdabcabcd" "")
--main = print $ findPattern "aaaa" ""
--main = print $ findPattern "aa" ""
--main = print $ findPattern "aaaa" ""
--main = print $ hasSubpattern "abbaabbaabba"

hasSubpattern :: String -> Bool
hasSubpattern s =
  length s
    /= 1
    && checkForPattern s (findPattern s (length s) "")
    && even (length s)
    || length s
    == length (filter (== firstLetter) s)
    && length s
    >  1
  where firstLetter = head s

checkForPattern :: String -> String -> Bool
checkForPattern s ps
  | null s                   = True
  | take (length ps) s == ps = checkForPattern (drop (length ps) s) ps
  | length s == length ps    = False
  | otherwise                = False

findPattern :: String -> Int -> String -> String
findPattern (c : s) ls ps
  | length s < ls `div` 2       = ""
  | ps == ""                    = c : findPattern s ls [c]
  | c == head ps && c /= head s = ""
  | c == head ps && c == head s = c : findPattern s ls ps
  | otherwise                   = c : findPattern s ls ps

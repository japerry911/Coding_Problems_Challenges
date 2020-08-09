{-
---Title Case---
A string is considered to be in title case if each word in the 
string is either (a) capitalised (that is, only the first letter 
of the word is in upper case) or (b) considered to be an exception 
and put entirely into lower case unless it is the first word, which 
is always capitalised.

Write a function that will convert a string into title case, 
given an optional list of exceptions (minor words). The list of 
minor words will be given as a string with each word separated by a 
space. Your function should ignore the case of the minor words string 
-- it should behave in the same way even if the case of the minor word 
string is changed.

###Arguments (Haskell)

First argument: space-delimited list of minor words that must always be 
lowercase except for the first word in the string.
Second argument: the original string to be converted.
###Arguments (Other languages)

First argument (required): the original string to be converted.
Second argument (optional): space-delimited list of minor words that must 
always be lowercase except for the first word in the string. The JavaScript/CoffeeScript 
tests will pass undefined when this argument is unused.
###Example

titleCase "a an the of" "a clash of KINGS" -- should return: "A Clash of Kings"
titleCase "The In" "THE WIND IN THE WILLOWS" -- should return: "The Wind in the Willows"
titleCase "" "the quick brown fox" -- should return: "The Quick Brown Fox"
-}

import           Data.Char
--import qualified Data.Text                     as T

main = print $ titleCase "a an the of" "an clash of KINGS"
--main = print $ titleCase "" "the quick brown fox"
--main = print $ titleCase "The In" "THE WIND IN THE WILLOWS"
--main = print $ titleCase "an often into" "First a of in"
--main = print $ lowerAll "a clash of KINGS"

titleCase :: String -> String -> String
titleCase minor toConvert = unwords
  (map
    (\s ->
      if s `elem` lowerAll minor && s /= take (length s)
                                              (unwords (lowerAll toConvert))
        then s
        else toUpper (head s) : tail s
    )
    (lowerAll toConvert)
  )

lowerAll :: String -> [String]
lowerAll s = map (map toLower) (words s)

{-titleCase :: String -> String -> String
titleCase minor toConvert = unwords
  (map
    (\s ->
      if T.isInfixOf (T.pack s) (T.pack (unwords (lowerAll minor))) && s /= take
           (length s)
           (unwords (lowerAll toConvert))
        then s
        else toUpper (head s) : tail s
    )
    (lowerAll toConvert)
  )

lowerAll :: String -> [String]
lowerAll s = map (map toLower) (words s)-}

--titleCase minor toConvert = map (all (`elem` minor)) (words toConvert)

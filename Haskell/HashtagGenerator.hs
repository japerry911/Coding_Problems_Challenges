{-
---Hashtag Generator---
The marketing team is spending way too much time typing in hashtags.
Let's help them with our own Hashtag Generator!

Here's the deal:

It must start with a hashtag (#).
All words must have their first letter capitalized.
If the final result is longer than 140 chars it must return false.
If the input or the result is an empty string it must return false.
Examples
" Hello there thanks for trying my Kata"  =>  "#HelloThereThanksForTryingMyKata"
"    Hello     World   "                  =>  "#HelloWorld"
""                                        =>  false
-}

import           Data.Char

main = print $ generateHashtag "A b\tcD e f\n"

generateHashtag :: String -> Maybe String
generateHashtag s =
  if null s
       || null (createHashtag s False)
       || length (createHashtag s False)
       >  140
    then Nothing
    else Just ('#' : createHashtag (unwords (words s)) True)

createHashtag :: String -> Bool -> String
createHashtag (c : s) bc
  | null s    = if isSpace c then "" else if bc then [toUpper c] else [c]
  | isSpace c = createHashtag s True
  | bc        = toUpper c : createHashtag s False
  | not bc    = c : createHashtag s False
  | otherwise = ""


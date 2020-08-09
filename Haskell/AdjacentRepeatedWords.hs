{-
---Adjacent Repeated Words in a String---
You know how sometimes you write the the same word twice in a sentence, 
but then don't notice that it happened? For example, you've been distracted 
for a second. Did you notice that *"the"* is doubled in the first sentence 
of this description?

As as aS you can see, it's not easy to spot those errors, especially if words 
    differ in case, like *"as"* at the beginning of the sentence.

Write a function that counts the number of sections repeating the same word 
(case insensitive). The occurence of two or more equal words next after each 
other count as one.

Example:

"dog cat"                 --> 0
"dog DOG cat"             --> 1
"apple dog cat"           --> 0
"pineapple apple dog cat" --> 0
"apple     apple dog cat" --> 1
"apple dog apple dog cat" --> 0
"dog dog DOG dog dog dog" --> 1
"dog dog dog dog cat cat" --> 2
"cat cat dog dog cat cat" --> 3
-}
import           Data.Char
import           Data.List

main = print $ countAdjacentPairs "apple dog apple dog cat"
--main = print $ "apple" == "apple"

countAdjacentPairs :: String -> Int
countAdjacentPairs s =
  length (filter (\s' -> length s' > 1) (group (words (lowerSentence s))))

lowerSentence :: String -> [Char]
lowerSentence s = [ toLower c | c <- s ]

{-countAdjacentPairs :: String -> Int
countAdjacentPairs s =
  countRepeatedSections [ lowerSentence s' | s' <- words s ] "" ""

lowerSentence :: String -> [Char]
lowerSentence s = [ toLower c | c <- s ]

countRepeatedSections :: [String] -> String -> String -> Int
countRepeatedSections (s : ss) ps pps
  | null ss             = if s == ps && s /= pps then 1 else 0
  | ps == ""            = countRepeatedSections ss s ""
  | s == ps && s /= pps = 1 + countRepeatedSections ss s s
  | s /= ps             = countRepeatedSections ss s ""
  | s == pps            = 0 + countRepeatedSections ss s s
  | otherwise           = 0-}

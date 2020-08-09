{-
---Word Mesh---
You will be given an array of strings. The words in the array should mesh 
together where one or more letters at the end of one word will have the same 
letters (in the same order) as the next word in the array. But, there are times 
when all the words won't mesh.

Examples of meshed words:

"apply" and "plywood"

"apple" and "each"

"behemoth" and "mother"

Examples of words that don't mesh:

"apply" and "playground"

"apple" and "peggy"

"behemoth" and "mathematics"

If all the words in the given array mesh together, then your code should return the 
meshed letters in a string. You won't know how many letters the meshed words have in 
common, but it will be at least one.

If all the words don't mesh together, then your code should return "failed to mesh".

Input: An array of strings. There will always be at least two words in the input array.

Output: Either a string of letters that mesh the words together or the string "failed to mesh".

Examples
#1:

["allow", "lowering", "ringmaster", "terror"] --> "lowringter"
because:

the letters "low" in the first two words mesh together
the letters "ring" in the second and third word mesh together
the letters "ter" in the third and fourth words mesh together.
#2:

["kingdom", "dominator", "notorious", "usual", "allegory"] --> "failed to mesh"
Although the words "dominator" and "notorious" share letters in the same order, the last 
letters of the first word don't mesh with the first letters of the second word.
-}

import           Data.Char

--main = print $ wordMesh ["allow", "lowering", "ringmaster", "terror"]
--main = print $ wordMesh ["allow", "allow"]
{--main =
  print $ wordMesh ["kingdom", "dominator", "notorious", "usual", "allegory"]

wordMesh :: [String] -> Maybe String
wordMesh ss =
  if any
       (== "")
       ([ if length (fst t) > length (snd t)
            then checkForMesh t
                              (drop (length (fst t) - length (snd t)) (fst t))
                              (length (snd t))
            else checkForMesh t (fst t) (length (fst t))
        | t <- zip ss (drop 1 ss)
        ]
       )
    then Nothing
    else Just
      (removeSpaces
        (unwords
          ([ if length (fst t) > length (snd t)
               then checkForMesh
                 t
                 (drop (length (fst t) - length (snd t)) (fst t))
                 (length (snd t))
               else checkForMesh t (fst t) (length (fst t))
           | t <- zip ss (drop 1 ss)
           ]
          )
        )
      )

checkForMesh :: (String, String) -> String -> Int -> String
checkForMesh t rs ri
  | rs == take ri (snd t) = rs
  | rs /= take ri (snd t) = checkForMesh t (drop 1 rs) (ri - 1)

removeSpaces :: String -> String
removeSpaces (c : s) | isAlpha c && null s = [c]
                     | isAlpha c           = c : removeSpaces s
                     | otherwise           = removeSpaces s
--}

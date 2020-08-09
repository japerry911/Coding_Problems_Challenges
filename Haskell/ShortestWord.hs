{-
---Shortest Word---
Simple, given a string of words, return the length of the shortest word(s).

String will never be empty and you do not need to account for different data types.
-}


main =
  print $ findShortest "bitcoin take over the world maybe who knows perhaps"

findShortest :: String -> Integer
findShortest s = toInteger (minimum (map length (words s)))

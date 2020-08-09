{-
---Highest Rank Number in an Array---
Complete the method which returns the number which is most 
frequent in the given input array. If there is a tie for most 
frequent number, return the largest number among them.

Note: no empty arrays will be given.

Examples
[12, 10, 8, 12, 7, 6, 4, 10, 12]              -->  12
[12, 10, 8, 12, 7, 6, 4, 10, 12, 10]          -->  12
[12, 10, 8, 8, 3, 3, 3, 3, 2, 4, 10, 12, 10]  -->   3
-}

main = print $ highestRank [10, 12, 8, 12, 7, 6, 4, 10, 12, 10]

highestRank :: [Int] -> Int
highestRank ns = fst
  (maxRank (head (map (\n -> (n, length (filter (== n) ns))) ns))
           (map (\n -> (n, length (filter (== n) ns))) ns)
  )
 where
  maxRank currentMax [] = currentMax
  maxRank (m, n) (p : ps) | n < snd p               = maxRank p ps
                          | n == snd p && m < fst p = maxRank p ps
                          | otherwise               = maxRank (m, n) ps

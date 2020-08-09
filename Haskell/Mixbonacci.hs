{-
---Mixbonacci---
This is the first of my "-nacci" series. If you like this kata, check out the zozonacci 
sequence too.

Task
Mix -nacci sequences using a given pattern p.
Return the first n elements of the mixed sequence.
Rules
The pattern p is given as a list of strings (or array of symbols in Ruby) using 
the pattern mapping below (e. g. ['fib', 'pad', 'pel'] means take the next fibonacci, 
then the next padovan, then the next pell number and so on).
When n is 0 or p is empty return an empty list.
If n is more than the length of p repeat the pattern.
Examples
            0  1  2  3  4  
----------+------------------
fibonacci:| 0, 1, 1, 2, 3 ...
padovan:  | 1, 0, 0, 1, 0 ...
pell:     | 0, 1, 2, 5, 12 ...

pattern = ['fib', 'pad', 'pel']
n = 6
#          ['fib',        'pad',      'pel',   'fib',        'pad',      'pel']
# result = [fibonacci(0), padovan(0), pell(0), fibonacci(1), padovan(1), pell(1)]
result = [0, 1, 0, 1, 0, 1]

pattern = ['fib', 'fib', 'pel']
n = 6
#          ['fib', 'fib', 'pel', 'fib', 'fib', 'pel']
# result = [fibonacci(0), fibonacci(1), pell(0), fibonacci(2), fibonacci(3), pell(1)]
result = [0, 1, 0, 1, 2, 1]
Sequences
fibonacci : 0, 1, 1, 2, 3 ...
padovan: 1, 0, 0, 1, 0 ...
jacobsthal: 0, 1, 1, 3, 5 ...
pell: 0, 1, 2, 5, 12 ...
tribonacci: 0, 0, 1, 1, 2 ...
tetranacci: 0, 0, 0, 1, 1 ...
Pattern mapping
'fib' -> fibonacci
'pad' -> padovan
'jac' -> jacobstahl
'pel' -> pell
'tri' -> tribonacci
'tet' -> tetranacci
If you like this kata, check out the zozonacci sequence.
-}

import           Data.List

{-main = print $ length
  (concat
    (replicate (51 `div` length ["fib", "fib", "pel", "pad"] + 1)
               ["fib", "fib", "pel", "pad"]
    )
  )-}
main = print $ mixbonacci ["pad", "pad", "pel", "pad"] 100
--main = print $ concat (replicate (10 `div` length ["tri"]) ["tri"])
--main = print $ mixbonacci ["tri"] 10
--main = print $ mixbonacci ["fib", "fib", "pel"] 6
--main = print $ mixbonacci ["pad"] 5
--main = print $ concat (replicate 2 ["fib", "fib", "pel"])
--main = print $ concat (replicate (10 `div` 3) ["jac", "jac", "pel"])
--main =
  --print $ mixbonacci (concat (replicate (10 `div` 3) ["jac", "jac", "pel"])) 10
--main = print $ mixbonacci (concat (replicate 10 ["tet"])) 10

mixbonacci :: [String] -> Int -> [Integer]
mixbonacci ss d
  | null ss || d == 0 = []
  | otherwise = map
    (\s -> if fst s == "fib"
      then fib1 (snd s)
      else if fst s == "pad"
        then padovan (snd s)
        else if fst s == "jac"
          then jacobstahl (snd s)
          else if fst s == "pel"
            then pell (snd s)
            else if fst s == "tri"
              then tribonacci (snd s)
              else if fst s == "tet" then tetranacci (snd s) else 0
    )
    (findonacci (concat (replicate (d `div` length ss + 1) ss)) d 0 0 [])

findonacci
  :: [String] -> Int -> Int -> Int -> [(String, Int)] -> [(String, Int)]
findonacci ss d di dc rs
  | di > (length ss - 1) = findonacci ss d 0 dc rs
  | null rs = findonacci ss (d - 1) (di + 1) (dc + 1) (rs ++ [(head ss, dc)])
  | d > 0 = findonacci
    ss
    (d - 1)
    (di + 1)
    (dc + 1)
    (rs ++ [(ss !! di, length (filter (== ss !! di) (take dc ss)))])
  | otherwise = rs

doAcci :: String -> Int -> Integer
doAcci s d = 1

{-fibonacci :: Int -> Integer
fibonacci 0 = 0
fibonacci 1 = 1
fibonacci d = fibonacci (d - 1) + fibonacci (d - 2)-}
fib1 n = snd . foldl fib_ (1, 0) . map (toEnum . fromIntegral) $ unfoldl divs n
 where
  unfoldl f x = case f x of
    Nothing     -> []
    Just (u, v) -> unfoldl f v ++ [u]

  divs 0 = Nothing
  divs k = Just (uncurry (flip (,)) (k `divMod` 2))

  fib_ (f, g) p | p         = (f * (f + 2 * g), f ^ 2 + g ^ 2)
                | otherwise = (f ^ 2 + g ^ 2, g * (2 * f - g))

padovan :: Int -> Integer
padovan 0 = 1
padovan 1 = 0
padovan 2 = 0
--padovan d = padovan (d - 2) + padovan (d - 3)
padovan d = fromIntegral ((1 - (d ^ 2)) `div` (1 - (d ^ 2) - (d ^ 3)))

jacobstahl :: Int -> Integer
jacobstahl 0 = 0
jacobstahl 1 = 1
jacobstahl d = jacobstahl (d - 1) + 2 * jacobstahl (d - 2)

pell :: Int -> Integer
pell 0 = 0
pell 1 = 1
pell d = 2 * pell (d - 1) + pell (d - 2)

tribonacci :: Int -> Integer
tribonacci 0 = 0
tribonacci 1 = 0
tribonacci 2 = 1
tribonacci d = tribonacci (d - 1) + tribonacci (d - 2) + tribonacci (d - 3)

tetranacci :: Int -> Integer
tetranacci 0 = 0
tetranacci 1 = 0
tetranacci 2 = 0
tetranacci 3 = 1
tetranacci d =
  tetranacci (d - 1) + tetranacci (d - 2) + tetranacci (d - 3) + tetranacci
    (d - 4)

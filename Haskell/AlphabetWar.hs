{-
---Alphabet War---
Introduction
There is a war and nobody knows - the alphabet war! There are 
two groups of hostile letters. The tension between left side 
letters and right side letters was too high and the war began.

Task
Write a function that accepts fight string consists of only small 
letters and return who wins the fight. When the left side wins 
return Left side wins!, when the right side wins return Right 
side wins!, in other case return Let's fight again!.

The left side letters and their power:

 w - 4
 p - 3
 b - 2
 s - 1
The right side letters and their power:

 m - 4
 q - 3
 d - 2
 z - 1
The other letters don't have power and are only victims.

Example
AlphabetWar("z");        //=> Right side wins!
AlphabetWar("zdqmwpbs"); //=> Let's fight again!
AlphabetWar("zzzzs");    //=> Right side wins!
AlphabetWar("wwwwwwz");  //=> Left side wins!
-}

main = print $ alphabetWar "zdqmwpbs"

alphabetWar :: String -> String
alphabetWar s | leftSideScore s > rightSideScore s = "Left side wins!"
              | leftSideScore s < rightSideScore s = "Right side wins!"
              | otherwise                          = "Let's fight again!"

leftSideScore :: [Char] -> Int
leftSideScore (c : s)
  | null s = if c == 'w'
    then 4
    else if c == 'p'
      then 3
      else if c == 'b' then 2 else if c == 's' then 1 else 0
  | c == 'w' = 4 + leftSideScore s
  | c == 'p' = 3 + leftSideScore s
  | c == 'b' = 2 + leftSideScore s
  | c == 's' = 1 + leftSideScore s
  | otherwise = 0 + leftSideScore s

rightSideScore :: [Char] -> Int
rightSideScore (c : s)
  | null s = if c == 'm'
    then 4
    else if c == 'q'
      then 3
      else if c == 'd' then 2 else if c == 'z' then 1 else 0
  | c == 'm' = 4 + rightSideScore s
  | c == 'q' = 3 + rightSideScore s
  | c == 'd' = 2 + rightSideScore s
  | c == 'z' = 1 + rightSideScore s
  | otherwise = 0 + rightSideScore s

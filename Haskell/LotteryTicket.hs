{-
---Lottery Ticket---
Time to win the lottery!

Given a lottery ticket (ticket), represented by an array of 2-value arrays, 
you must find out if you've won the jackpot. Example ticket:

[ [ 'ABC', 65 ], [ 'HGR', 74 ], [ 'BYHT', 74 ] ]
To do this, you must first count the 'mini-wins' on your ticket. Each sub array 
has both a string and a number within it. If the character code of any of the 
characters in the string matches the number, you get a mini win. Note you can 
only have one mini win per sub array.

Once you have counted all of your mini wins, compare that number to the other 
input provided (win). If your total is more than or equal to (win), return 
'Winner!'. Else return 'Loser!'.

All inputs will be in the correct format. Strings on tickets are not always the same length.
-}

import           Data.Char

main = print $ bingo [("HGTYRE", 74), ("BE", 66), ("JKTY", 74)] 3
--main = print $ checkTicket "HGR" (chr 74)

bingo :: [(String, Int)] -> Int -> String
bingo ts d = if countMiniWins ts >= d then "Winner!" else "Loser!"

countMiniWins :: [(String, Int)] -> Int
countMiniWins (t : ts)
  | null ts = if checkTicket (fst t) (chr (snd t)) then 1 else 0
  | checkTicket (fst t) (chr (snd t)) = 1 + countMiniWins ts
  | otherwise = 0 + countMiniWins ts

checkTicket :: String -> Char -> Bool
checkTicket (c : s) c' | c == c'   = True
                       | null s    = False
                       | otherwise = checkTicket s c'

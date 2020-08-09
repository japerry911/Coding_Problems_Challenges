{-
---Blackjack Scorer---
The function receives an array of strings that represent each card in the hand
("2", "3", ..., "10", "J", "Q", "K" or "A") and should return the score of the hand (integer).

Scoring rules:
Number cards count as their face value (2 through 10). Jack, Queen and King count as 10. 
An Ace can be counted as either 1 or 11.

Return the highest score of the cards that is less than or equal to 21. If there is no 
score less than or equal to 21 return the smallest score more than 21.

Examples
["A"]                           ==>  11
["A", "J"]                      ==>  21
["A", "10", "A"]                ==>  12
["5", "3", "7"]                 ==>  15
["5", "4", "3", "2", "A", "K"]  ==>  25
-}

main = print $ scoreHand ["A"]
--main = print $ pushAsToBack ["5", "4", "3", "2", "A", "K"]

scoreHand :: [String] -> Int
scoreHand ss = evaluateHand (pushAsToBack ss) 0

evaluateHand :: [String] -> Int -> Int
evaluateHand (s : ss) dt
  | null ss && s == "A" = if dt + 11 > 21 then dt + 1 else dt + 11
  | null ss = dt + evaluateCard s
  | s == "A" = if dt >= 10
    then evaluateHand ss (dt + 1)
    else evaluateHand ss (dt + 11)
  | otherwise = evaluateHand ss (dt + evaluateCard s)

evaluateCard :: String -> Int
evaluateCard s
  | s `elem` ["J", "K", "Q"] = 10
  | s `elem` ["2", "3", "4", "5", "6", "7", "8", "9", "10"] = read s
  | otherwise                = 0

pushAsToBack :: [String] -> [String]
pushAsToBack ss = filter (/= "A") ss ++ filter (== "A") ss

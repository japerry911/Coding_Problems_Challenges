module UFC where

import           Data.Char

fighter :: String -> String
fighter str
  | compareCaseInsensitive str "conor mcgregor"
  = "I'd like to take this chance to apologize.. To absolutely NOBODY!"
  | otherwise
  = "I am not impressed by your performance."

compareCaseInsensitive :: String -> String -> Bool
compareCaseInsensitive (c : s) (ck : sk)
  | null s          = toLower c == ck
  | toLower c == ck = compareCaseInsensitive s sk
  | otherwise       = False

{-
---PrinterErrors---
In a factory a printer prints labels for boxes. For one kind of boxes the printer has to use 
colors which, for the sake of simplicity, are named with letters from a to m.

The colors used by the printer are recorded in a control string. For example a "good" control 
string would be aaabbbbhaijjjm meaning that the printer used three times color a, four times 
color b, one time color h then one time color a...

Sometimes there are problems: lack of colors, technical malfunction and a "bad" control string 
is produced e.g. aaaxbbbbyyhwawiwjjjwwm with letters not from a to m.

You have to write a function printer_error which given a string will output the error rate of 
the printer as a string representing a rational whose numerator is the number of errors and
the denominator the length of the control string. Don't reduce this fraction to a simpler expression.

The string has a length greater or equal to one and contains only letters from ato z.

#Examples:

s="aaabbbbhaijjjm"
error_printer(s) => "0/14"

s="aaaxbbbbyyhwawiwjjjwwm"
error_printer(s) => "8/22"
-}

main :: IO ()
main = print $ printerError "tekcmjlmcafbadfjbmkedechfjckjbkjjcje"

printerError :: [Char] -> [Char]
printerError s = show errNum ++ "/" ++ show totalNum
 where
  errNum   = length (filter (`elem` ['n' .. 'z']) s)
  totalNum = length s

{-printerError :: [Char] -> [Char]
printerError (c : s)
  | null s
  = if c
       `notElem` [ 'a'
                 , 'b'
                 , 'c'
                 , 'd'
                 , 'e'
                 , 'f'
                 , 'g'
                 , 'h'
                 , 'i'
                 , 'j'
                 , 'k'
                 , 'l'
                 , 'm'
                 ]
    then
      "1/1"
    else
      "0/1"
  | c
    `notElem` ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm']
  = show (findErrors s + 1) ++ "/" ++ show (length s + 1)
  | otherwise
  = show (findErrors s) ++ "/" ++ show (length s + 1)
{-printerError (c : s) = if null s
  then
    (if c
        `notElem` [ 'a'
                  , 'b'
                  , 'c'
                  , 'd'
                  , 'e'
                  , 'f'
                  , 'g'
                  , 'h'
                  , 'i'
                  , 'j'
                  , 'k'
                  , 'l'
                  , 'm'
                  ]
     then
       "1/1"
     else
       "0/1"
    )
  else
    if c
       `notElem` [ 'a'
                 , 'b'
                 , 'c'
                 , 'd'
                 , 'e'
                 , 'f'
                 , 'g'
                 , 'h'
                 , 'i'
                 , 'j'
                 , 'k'
                 , 'l'
                 , 'm'
                 ]
    then
      show (findErrors s + 1) ++ "/" ++ show (length s + 1)
    else
      show (findErrors s + 1) ++ "/" ++ show (length s + 1)-}

findErrors :: [Char] -> Int
findErrors (c : s)
  | not (null s)
  = if c
       `notElem` [ 'a'
                 , 'b'
                 , 'c'
                 , 'd'
                 , 'e'
                 , 'f'
                 , 'g'
                 , 'h'
                 , 'i'
                 , 'j'
                 , 'k'
                 , 'l'
                 , 'm'
                 ]
    then
      1 + findErrors s
    else
      0 + findErrors s
  | c
    `notElem` ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm']
  = 1
  | otherwise
  = 0

{-findErrors (c : s) = if not (null s)
  then
    (if c
        `notElem` [ 'a'
                  , 'b'
                  , 'c'
                  , 'd'
                  , 'e'
                  , 'f'
                  , 'g'
                  , 'h'
                  , 'i'
                  , 'j'
                  , 'k'
                  , 'l'
                  , 'm'
                  ]
     then
       1 + findErrors s
     else
       0 + findErrors s
    )
  else
    (if c
        `notElem` [ 'a'
                  , 'b'
                  , 'c'
                  , 'd'
                  , 'e'
                  , 'f'
                  , 'g'
                  , 'h'
                  , 'i'
                  , 'j'
                  , 'k'
                  , 'l'
                  , 'm'
                  ]
     then
       1
     else
       0
    )-}
-}

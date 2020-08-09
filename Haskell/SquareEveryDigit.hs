{-
---Square Every Digit---
Welcome. In this kata, you are asked to square every digit of a number.

For example, if we run 9119 through the function, 811181 will come out, because 92 is 81 and 12 is 1.

Note: The function accepts an integer and returns an integer
-}

main = print $ squareDigit (-2112)

squareDigit :: Int -> Int
squareDigit n
  | n == (-1) = -1
  | n `mod` (-10) > (-10) && n < (-9) = read
    ("-" ++ show (squareDigit (n `div` (-10))) ++ show
      ((n `mod` (-10)) * (n `mod` (-10)))
    )
  | n `mod` 10 < 10 && n > 9 = read
    (show (squareDigit (n `div` 10)) ++ show ((n `mod` 10) * (n `mod` 10)))
  | n < 10 && n > 0 = (n `mod` 10) * (n `mod` 10)
  | n > (-10) && n < 0 = (n `mod` (-10)) * (n `mod` (-10))
  | otherwise = 0

{-
squareDigit n
  | n < 0 = negate (squareDigit (negate n))
  | otherwise = read (show n >>= (show . (^2) . digitToInt))
-}

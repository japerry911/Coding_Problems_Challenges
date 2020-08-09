{-
---Sum of the First nth Series---
Task:
Your task is to write a function which returns the sum of following series upto nth term(parameter).

Series: 1 + 1/4 + 1/7 + 1/10 + 1/13 + 1/16 +...
Rules:
You need to round the answer to 2 decimal places and return it as String.

If the given value is 0 then it should return 0.00

You will only be given Natural Numbers as arguments.

Examples:
SeriesSum(1) => 1 = "1.00"
SeriesSum(2) => 1 + 1/4 = "1.25"
SeriesSum(5) => 1 + 1/4 + 1/7 + 1/10 + 1/13 = "1.57"
NOTE: In PHP the function is called series_sum().
-}

main = print $ seriesSum 1

seriesSum :: Integer -> String
seriesSum n = do
  let result = show (digits (calcSum n) 2)
  if length result <= 3 then result ++ "0" else result


calcSum :: Integer -> Float
calcSum n
  | n == 1 = 1 + calcSum (n - 1) * 10 ^ 2
  | n > 1 = 1.0 / (((fromIntegral n :: Float) - 1) * 3.0 + 1.0) + calcSum
    (n - 1)
  | n == 0 = 0.00

digits d n = fromInteger (round (d * 10 ^ n)) / 10 ^ n

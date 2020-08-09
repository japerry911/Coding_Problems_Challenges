{-
---Even or Odd---
Create a function (or write a script in Shell) that takes an integer as an 
argument and returns "Even" for even numbers or "Odd" for odd numbers.
-}

main = print $ evenOrOdd 3

evenOrOdd :: Integral a => a -> [Char]
{-evenOrOdd n = if even n then "Even" else "Odd"-}
evenOrOdd n | even n    = "Even"
            | otherwise = "Odd"

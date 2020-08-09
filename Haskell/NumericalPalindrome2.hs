{-
---Numerical Palindrome #2---
A palindrome is a word, phrase, number, or other sequence of characters which reads 
the same backward as forward. Examples of numerical palindromes are:

2332
110011
54322345

For this kata, single digit numbers will not be considered numerical palindromes.

For a given number num, write a function to test if the number contains a numerical 
palindrome or not and return a boolean (true if it does and false if does not). 
Return "Not valid" if the input is not an integer or is less than 0.

Note: Palindromes should be found without permutating num.

palindrome(5) => false
palindrome(1221) => true
palindrome(141221001) => true
palindrome(1215) => true 
palindrome(1294) => false 
palindrome("109982") => "Not valid"

In Haskell, this returns a Maybe Bool, with Nothing for an input less than zero.
-}

main = print $ palindrome 123322367
--main = print $ checkForPalindromes (splitNumberToList 141221001) 2

palindrome :: Integer -> Maybe Bool
palindrome d | d >= 0    = Just (checkForPalindromes (splitNumberToList d) 2)
             | otherwise = Nothing

splitNumberToList :: Integer -> [Integer]
splitNumberToList d | d > 0     = splitNumberToList (d `div` 10) ++ [d `mod` 10]
                    | otherwise = []

checkForPalindromes :: [Integer] -> Int -> Bool
checkForPalindromes ds di
  | null ds
  = False
  | di > length ds
  = checkForPalindromes (drop 1 ds) 2
  | take di ds == reverse (take di ds) || drop (length ds - di) ds == reverse
    (drop (length ds - di) ds)
  = True
  | otherwise
  = checkForPalindromes ds (di + 1)

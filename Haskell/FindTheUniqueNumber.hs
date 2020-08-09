{-
---Find the Unique Number---
Write a function called findUnique which returns the only unique 
number from an array.

All numbers in the unsorted array are present twice, except the one 
you have to find. The numbers are always valid integer values between 
1 and 2147483647, so no need for type and error checking. The array contains 
at least one number and may contain millions of numbers. So make sure your 
solution is optimized for speed.

Example
Input:

[ 1, 8, 4, 4, 6, 1, 8 ]
Expected output:

6
-}

import           Data.List

main = print $ findUnique [-59, -5, -5]

findUnique :: [Int] -> Int
findUnique ds | length ds > 1 = discoverUnique (sort ds) 1000000
              | otherwise     = head ds

discoverUnique :: [Int] -> Int -> Int
discoverUnique (d : ds) dp | d `elem` ds || d == dp = discoverUnique ds d
                           | otherwise              = d

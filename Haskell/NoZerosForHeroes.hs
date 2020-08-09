{-
---No Zeros for Heroes---
Numbers ending with zeros are boring.

They might be fun in your world, but not here.

Get rid of them. Only the ending ones.

1450 -> 145
960000 -> 96
1050 -> 105
-1050 -> -105
Zero alone is fine, don't worry about it. Poor guy anyway
-}

main = print $ noBoringZeros 0

noBoringZeros :: Int -> Int
noBoringZeros n | n == 0          = 0
                | n `mod` 10 == 0 = noBoringZeros (n `div` 10)
                | otherwise       = n

{-
---Power of Two---
Complete the function power_of_two/powerOfTwo (or equivalent, depending on your 
language) that determines if a given non-negative integer is a power of two. From 
    the corresponding Wikipedia entry:

a power of two is a number of the form 2n where n is an integer, i.e. the result of 
    exponentiation with number two as the base and integer n as the exponent.

You may assume the input is always valid.

Examples
isPowerOfTwo       1 `shouldBe` True
isPowerOfTwo       2 `shouldBe` True
isPowerOfTwo       6 `shouldBe` False
isPowerOfTwo       8 `shouldBe` True
isPowerOfTwo    1024 `shouldBe` True
isPowerOfTwo    1026 `shouldBe` False
Beware of certain edge cases - for example, 1 is a power of 2 since 2^0 = 1 and 0 is 
not a power of 2.
-}

import           Data.Bits

main = print $ isPowerOfTwo 0

isPowerOfTwo :: Int -> Bool
isPowerOfTwo n = (.&.) n (-n) == n && n /= 0

{-isPowerOfTwo :: Int -> Bool
isPowerOfTwo n | even n    = isPowerOfTwo (n `div` 2)
               | n == 1    = True
               | otherwise = False-}

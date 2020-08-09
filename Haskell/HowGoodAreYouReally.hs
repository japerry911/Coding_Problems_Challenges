{-
---How Good are you Really?---
There was a test in your class and you passed it. Congratulations!
But you're an ambitious person. You want to know if you're better than the average student in your class.

You receive an array with your peers' test scores. Now calculate the average and compare your score!

Return True if you're better, else False!

Note:
Your points are not included in the array of your class's points. For calculating the average point you may 
add your point to the given array!
-}

main = print $ betterThanAverage [100, 40, 34, 57, 29, 72, 57, 88] 75

betterThanAverage :: [Int] -> Int -> Bool
betterThanAverage ds d | d > averageArray ds (length ds) 0 = True
                       | otherwise                         = False

averageArray :: [Int] -> Int -> Int -> Int
averageArray (di : ds) dsl d | null ds   = (d + di) `div` dsl
                             | otherwise = averageArray ds dsl (di + d)

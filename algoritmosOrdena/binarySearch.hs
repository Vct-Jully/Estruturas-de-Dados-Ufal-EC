import Data.Array

binarySearch :: Array Int Int -> Int -> Int -> Int -> Int 

binarySearch aarray element begin end
    | begin > end = -1
    | aarray ! middle < element = binarySearch aarray element (middle+1) end
    | aarray ! middle > element = binarySearch aarray element begin (middle-1)
    | otherwise = middle
    where
        middle = (begin + end) `div` 2

main :: IO ()
main = do

    let aarray = array (0,9) [(0, 1), (1, 2), (2, 3), (3, 4), (4, 5), (5, 6), (6, 7), (7, 8), (8, 9), (9, 10)]
    let result = binarySearch aarray 3 0 9

    print result
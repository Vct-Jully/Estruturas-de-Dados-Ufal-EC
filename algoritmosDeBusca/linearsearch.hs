linearSearch :: Int -> [Int] -> Bool
linearSearch e [] = False
linarSearch e (a:as) = if (a == e) then True
    else linearSearch e as
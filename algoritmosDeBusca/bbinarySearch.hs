import Data.Array

-- Definição da função de busca binária
binarySearch :: (a0, b0) -> [(a1, b1)] -> t0
binarySearch array element begin end
    | begin > end = -1
    | array ! middle < element = binarySearch array element (middle + 1) end
    | array ! middle > element = binarySearch array element begin (middle - 1)
    | otherwise = middle
    where
        middle = (begin + end) `div` 2

-- Função principal para testar a busca binária
main :: IO ()
main = do
    let array = array (0, 9) [(0, 1), (1, 2), (2, 3), (3, 4), (4, 5), 
                             (5, 6), (6, 7), (7, 8), (8, 9), (9, 10)]
    let result = binarySearch array 3 0 9
    print result

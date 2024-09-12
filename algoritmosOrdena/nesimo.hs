import Data.Array

nesimo :: Int -> Array Int Int -> Int
  | nesimo 1 (x : _) = x
  | nesimo n numbers = numbers ! (n - 1)

main :: IO ()
main = do
  let numbers = array (0, 5) [(0, 2), (1, 4), (2, 7), (3, 6)]

  let result = nesimo 3 numbers

  print result
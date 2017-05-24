module Main where

main :: IO ()
main = print . (fib !!) . pred =<< readLn
  where fib = 0:scanl (+) 1 fib :: [Int]

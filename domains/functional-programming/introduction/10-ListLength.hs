module Main where

len :: [a] -> Int
len []     = 0
len (_:xs) = 1 + len xs

main :: IO ()
main = putStrLn "Introductions | 10 - List Length" 

module Main where

rev :: [a] -> [a]
rev = flip (:) `foldl` []

main :: IO ()
main = putStrLn "Introductions | 8 - Reverse A List" 

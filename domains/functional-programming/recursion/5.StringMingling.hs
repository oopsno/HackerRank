module Main where

main :: IO ()
main = putStrLn . (\(x:y:_) -> concat $ zipWith (\a b -> a:b:[]) x y) . lines =<< getContents

module Main where

main :: IO ()
main = mapM_ (print . abs . (read :: String -> Int)) . words =<< getContents

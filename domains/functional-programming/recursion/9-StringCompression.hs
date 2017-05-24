module Main where

import Data.List

compress :: String -> String
compress xs | length xs == 1 = xs
            | otherwise      = (head xs):(show $ length xs)

main :: IO ()
main = putStrLn . concat . map compress . group =<< getContents

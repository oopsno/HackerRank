module Main where

import Control.Monad

main :: IO ()
main = print =<< liftM (sum . filter odd . map (read :: String -> Int) . lines) getContents

module Main ( main ) where

import Control.Monad

main :: IO ()
main = print =<< liftM (sum . map (read :: String -> Int) . words) getContents

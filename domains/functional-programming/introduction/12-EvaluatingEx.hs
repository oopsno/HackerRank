module Main where

import Control.Monad

terms :: Double -> [Double]
terms x = scanl1 (\r n -> r * x / (n-1)) [1..10]

main :: IO ()
main = mapM_ print =<< liftM (map (sum . terms . read) . tail . lines) getContents

module Main where

import Control.Monad

main :: IO ()
main = do
  n  <- readLn
  xs <- liftM lines getContents
  forM_ xs $ replicateM_ n . putStrLn 

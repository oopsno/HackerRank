module Main where

import Control.Monad

main :: IO ()
main = readLn >>= flip replicateM_ (putStrLn "Hello World")

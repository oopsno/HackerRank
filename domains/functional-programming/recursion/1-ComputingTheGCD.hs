module Main where

import Control.Monad

myGCD :: Int -> Int -> Int
myGCD x y = case compare x y of
   EQ -> x
   GT -> myGCD y $ x - y
   LT -> myGCD y x

main :: IO () 
main = print =<< liftM ((\(x:y:_) -> myGCD x y) . map read . words) getContents

module Main where

fn :: Int -> [Int]
fn n = [1..n]

main :: IO ()
main = print . fn =<< readLn

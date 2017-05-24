module Main where

swap :: [a] -> [a]
swap [] = []
swap [x] = [x]
swap (x:y:zs) = y:x:(swap zs)

main :: IO ()
main = mapM_ putStrLn . map swap . tail . lines =<< getContents

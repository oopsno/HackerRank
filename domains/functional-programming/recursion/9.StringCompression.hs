import Data.List

compress xs@(_:[]) = xs
compress xs@(x:_)  = x:(show $ length xs)

main = putStrLn . concat . map compress . group =<< getContents

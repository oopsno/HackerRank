import Data.Array.Unboxed

buildMatrix :: [[Int]] -> [UArray Int Int]
buildMatrix ((upBound:[]):xs) = map (listArray (0, upBound - 1)) xs
sumDiagonal xs = sum $ zipWith (!) xs [0..]
diff xs = abs $ (sumDiagonal xs) - (sumDiagonal $ reverse xs)
main = print . diff . buildMatrix . map (map read . words) . lines =<< getContents 

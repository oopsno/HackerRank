import Control.Monad

main :: IO ()
main = liftM (map read . lines) getContents
         >>= \(x:xs) -> mapM_ print $ filter (<x) (xs :: [Int])


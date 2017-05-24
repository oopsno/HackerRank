import Data.List

sharps = iterate ('#':) "#"
spaces n = iterate tail $ replicate (n-1) ' '
main = mapM_ putStrLn . (\n -> take n $ zipWith (++) (spaces n) sharps) =<< readLn

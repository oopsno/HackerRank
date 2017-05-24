pascal :: [[Int]]
pascal = iterate evolve [1]
  where evolve xs = zipWith (+) (0:xs) (xs ++ [0])

main :: IO ()
main = mapM_ (putStrLn . unwords . map show) . flip take pascal =<< readLn

magic (x:xs) = 
  let (p, n, z) = foldl fn (0, 0, 0) xs in [p/x, n/x, z/x]
  where fn (p,n,z) e = case compare e 0 of
                         LT -> (p, n + 1, z)
                         EQ -> (p, n, z + 1)
                         GT -> (p + 1, n ,z)

main = mapM_ print . magic . map read . words =<< getContents

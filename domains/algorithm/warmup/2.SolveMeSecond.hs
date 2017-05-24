main = mapM_ (print . sum) . map (map read . words) . tail . lines =<< getContents

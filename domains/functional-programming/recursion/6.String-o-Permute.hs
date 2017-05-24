swap [] = []
swap (x:y:zs) = y:x:(swap zs)

main = mapM_ putStrLn . map swap . tail . lines =<< getContents



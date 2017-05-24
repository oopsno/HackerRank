import Control.Monad

main = print =<< liftM (sum . map read . words) getContents

import Control.Monad

main = print =<< liftM (sum . filter odd . map read . lines) getContents

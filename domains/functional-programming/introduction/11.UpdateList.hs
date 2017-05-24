import Control.Monad

main = mapM_ print =<< liftM (map abs . map read . lines) getContents

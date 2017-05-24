import Control.Monad

genploy :: [Double] -> [Double] -> Double -> Double
genploy as bs x = sum $ zipWith (\a b ->a * x ** b) as bs

genslices :: Double -> Double -> Double -> [Double]
genslices l r s = [l,l+s..r]

readLnList :: Read a => IO [a]
readLnList = liftM (map read . words) getLine

main :: IO ()
main = do
  as      <- readLnList
  bs      <- readLnList
  (l:r:_) <- readLnList
  let step   = 0.001
      poly   = genploy as bs
      slices = genslices l r step
      values = map poly slices
      area   = sum $ map (*step)                    values
      vol    = sum $ map (\x -> pi * x ** 2 * step) values
  print area
  print vol


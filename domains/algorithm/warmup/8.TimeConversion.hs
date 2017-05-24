import Data.List.Split
import Text.Printf

magic s = do
  let (h:_:m:_:s:x:_) = splitPlaces [2, 1, 2, 1, 2, 2] s :: [String]
      h'              = (read h :: Int) + if elem 'P' x then 12 else 0
  printf "%02d:%s:%s"  h' m s
              
main = magic =<< getLine


import Control.Monad

data Position = Odd | Even deriving Eq
data Picker = Picker { pos :: Position, ctx :: [String] }

instance Show Picker where
  show = unlines . reverse . ctx

pickOnEven = foldl pickOnEven' $ Picker Odd []
  where pickOnEven' r x | pos r == Even = r { pos = Odd, ctx = x:ctx r }
                        | otherwise     = r { pos = Even }

main = print =<< liftM (pickOnEven . lines) getContents

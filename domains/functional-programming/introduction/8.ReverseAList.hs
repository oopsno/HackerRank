module ReverseList ( rev ) where

rev :: [a] -> [a]
rev = flip (:) `foldl` []

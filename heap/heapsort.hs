-- Haskell program to perform heapsort
import Data.Graph.Inductive.Internal.Heap(
  Heap(..),insert,findMin,deleteMin)

-- Build the given array into heap
build :: Ord a => [(a,b)] -> Heap a b
build = foldr insert Empty

-- Max heapify
toList :: Ord a => Heap a b -> [(a,b)]
toList Empty = []
toList h = x:toList r
           where (x,r) = (findMin h,deleteMin h)

-- Sort the given array
heapsort :: Ord a => [a] -> [a]
heapsort = (map fst) . toList . build . map (\x->(x,x))

-- Begin main
main=do
	input<-getLine  -- get input
	let n=(read input)::[Int]  -- convert input to list of integers
	heapsort n  -- call heapsort function on input list
	return()
-- End main

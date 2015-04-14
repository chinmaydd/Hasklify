-- Haskell program to perform heapsort
import Data.Graph.Inductive.Internal.Heap(
  Heap(..),insert,findMin,deleteMin)

-- Build the given array into heap
build :: Ord a => [(a,b)] -> Heap a b  -- build takes a list of (a,b) pairs, returns a heap
build = foldr insert Empty  -- 

-- Max heapify
toList :: Ord a => Heap a b -> [(a,b)]
toList Empty = []
toList h = x:toList r
           where (x,r) = (findMin h,deleteMin h)

-- Sort the given array
heapsort :: Ord a => [a] -> [a]  -- heapsort takes a list and returns a list
heapsort = (map fst) . toList . build . map (\x->(x,x))  {- takes the list, creates a pair (x,x) for each element, calls build, 
converts returned heap to list, and applies fst to each element of the heap -}

-- Begin main
main=do
	input<-getLine  -- get input
	let n=(read input)::[Int]  -- convert input to list of integers
	heapsort n  -- call heapsort function on input list
	return()
-- End main

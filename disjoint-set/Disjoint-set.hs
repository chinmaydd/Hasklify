{-
Haskell implementation of Disjoint-set Data Structure
-}
find::Int->[Int]->Int --find operation of Data Structure
find x xs
	|x==y = x
	|otherwise = find y xs
	where y=xs!!x

union::Int->Int->[Int]->[Int]  --union operation of Data Structure
union x y xs=replaceNth (find x xs) (find y xs) xs	 


replaceNth::Int->Int->[Int]->[Int] -- replacing the ith element of list (Complexity O(n))
replaceNth n newVal (x:xs)
     | n == 0 = newVal:xs
     | otherwise = x:replaceNth (n-1) newVal xs

main=do putStrLn "Enter Number of elements :"
	str<-getLine
	let n=read str
	let set=[0..n-1] --Disjoint set declaration and initialisation
	putStrLn "Enter Number of operations :"
	str<-getLine
	let n=read str
	action n set

action 0 _=return()
action n set=do   --simulates for loop using recursion
	putStrLn "Enter sets to do union :"
  	str<-getLine
	let x=read str::Int
	str<-getLine
	let y=read str::Int
	let set1=union x y set
	let set=set1
	putStrLn $ show set
	putStrLn "Enter element to do find :" 
	str<-getLine
	let x=read str::Int
	putStrLn $ show $ find x set
	action (n-1) set  --recursive call for next iteration

{-
Haskell implementation of Disjoint-set Data Structure
-}
find::Int->[Int]->Int --find operation of Data Structure
find x xs
	|x==y = x --if parent return
	|otherwise = find y xs --if not parent continue find
	where y=xs!!x

union::Int->Int->[Int]->[Int]  --union operation of Data Structure
union x y xs=replaceNth (find x xs) (find y xs) xs --make  y's representative , parent of x's representive	 


replaceNth::Int->Int->[Int]->[Int] -- replacing the ith element of list (Complexity O(n))
replaceNth n newVal (x:xs)
     | n == 0 = newVal:xs
     | otherwise = x:replaceNth (n-1) newVal xs

main=do putStrLn "Enter Number of elements :"  --main function
	str<-getLine  	 	
	let n=read str   --number of elements in set
	let set=[0..n-1] --Disjoint set declaration and initialisation
	putStrLn "Enter Number of operations :"
	str<-getLine
	let n=read str --number of operations to be performed
	action n set

action 0 _=return() --terminating loop
action n set=do   --simulates for loop using recursion
	putStrLn "Enter sets to do union :"
  	str<-getLine
	let x=read str::Int --first set
	str<-getLine
	let y=read str::Int --second set
	let set1=union x y set --union operation performed
	let set=set1
	putStrLn $ show set --printing disjoint set representation
	putStrLn "Enter element to do find :"  
	str<-getLine
	let x=read str::Int --element to be searched
	putStrLn $ show $ find x set --find operation performed
	action (n-1) set  --recursive call for next iteration

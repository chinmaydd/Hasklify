find::Int->[Int]->Int
find x xs
	|x==y = x
	|otherwise = find y xs
	where y=xs!!x

union::Int->Int->[Int]->[Int]
union x y xs=replaceNth (find x xs) (find y xs) xs	 


replaceNth::Int->Int->[Int]->[Int]
replaceNth n newVal (x:xs)
     | n == 0 = newVal:xs
     | otherwise = x:replaceNth (n-1) newVal xs

main=do putStrLn "Enter Number of elements :"
	str<-getLine
	let n=read str
	let set=[0..n-1]
	putStrLn "Enter Number of operations :"
	str<-getLine
	let n=read str
	action n set

action 0 _=return()
action n set=do
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
	action (n-1) set

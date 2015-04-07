--Haskell Implementation of Queue 
type Queue = [Int]

pop :: Queue -> Queue
pop s = tail s

push :: Int -> Queue -> Queue
push c s = s ++ [c]  

main=do
	putStrLn"Enter the element to push"
        str<-getLine
	let n=read str::Int
	let s=[1,2,3,4,5,6]
	let s1=push n s
	let s=s1
        putStrLn"The queue after pushing is:"
	putStrLn $ show s
	let s1=pop s
	let s=s1
        putStrLn"The queue after poping:"
	putStrLn $ show s


-- This  is an implementation of Stack using Haskell's list operators

-- type synonym for a Stack

type Stack = [Int]

pop :: Stack -> Stack
pop s = tail s

push :: Int -> Stack -> Stack
push c s = c:s  
     
showStack :: Stack -> IO()
showStack [] = error "Stack empty"
showStack s = print  s

main=do
	
	putStrLn "Enter value to be pushed"
	str<-getLine
	let n=read str::Int
	let s=[34,1,23,90]
	let s1=push n s
	let s=s1
	putStrLn "Stack Status:"
	showStack s
	let s1=pop s
	let s=s1
	putStrLn "Stack status after pop:"
	showStack s

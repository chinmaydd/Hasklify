
-- This  is an implementation of Stack using Haskell's list operator

-- type synonym for a Stack

type Stack = [Int]

pop :: Stack -> Stack --pop function takes stack type as input parameter and returns stack type
pop s = tail s --'tail' returns all elements except the first element of a list

push :: Int -> Stack -> Stack --push function takes stack type and int type as input parameters and returns stack type
push c s = c:s  -- 'c:s' adds c to front of list s  
     
showStack :: Stack -> IO() --showStack function takes stack type as input parameter and prints output on screen(IO)
showStack [] = error "Stack empty"
showStack s = print  s

main = do
	
	putStrLn "Enter value to be pushed"
	str<-getLine -- get input
	let n = read str::Int --typecast input to int type
	let s = [34,1,23,90] --declaration of list
	let s1 = push n s --lists in haskell are immutable and therefore,a temporary list has been used to make permanent changes
	let s = s1
	putStrLn "Stack Status:"
	showStack s
	let s1=pop s
	let s=s1
	putStrLn "Stack status after pop:"
	showStack s

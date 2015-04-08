--Haskell Implementation of Queue 
type Queue = [Int]                                   --assigning the type [Int] to 'Queue' so they are interchangable

dequeue :: Queue -> Queue                            --Function prototype ie- it takes in type Queue and return type Queue      
dequeue s = tail s                                   --Definition of the function. 'tail' returns all elements except the first one     

enqueue :: Int -> Queue -> Queue                     --Function prototype ie- it takes in type Int and type Queue and return type Queue
enqueue c s = s ++ [c]                               --The operarator ++ adds a list the end of another list

main=do
	putStrLn"Enter the element to push"
        str<-getLine
	let n=read str::Int
	let s=[1,2,3,4,5,6]
	let s1=enqueue n s
	let s=s1
        putStrLn"The queue after enqueue is:"
	putStrLn $ show s
	let s1=dequeue s
	let s=s1
        putStrLn"The queue after dequeue:"
	putStrLn $ show s

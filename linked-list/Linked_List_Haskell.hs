type LinkedList = [Int]

front :: LinkedList -> Int
front s = head s

end :: LinkedList -> Int
end s = last s

ins :: Int -> LinkedList -> LinkedList
ins c s = s++[c]

delete :: LinkedList -> LinkedList
delete s = init s

isEmpty :: LinkedList -> Bool
isEmpty [] = True
isEmpty _ = False

showLinkedList :: LinkedList -> IO()
showLinkedList [] = print "LinkedList empty"
showLinkedList s = print s

main=do 
	str<-getLine
	let n=read str
	let set = []
	action n set

action 0 _=return()
action n set=do
  	str<-getLine
	let x=read str::Int
	if (x==1)
	then do
		str<-getLine
		let temp=read str::Int
		let s1 = ins temp set
		let set = s1
		action (n-1) set
	else if(x==2)
	then do
		let s1 = delete set
		let set = s1
		action (n-1) set
	else if(x==3)
	then do
		showLinkedList set
		action (n-1) set
	else 
		action (n-1) set
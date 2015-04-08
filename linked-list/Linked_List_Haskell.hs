-- This  is an implementation of Linked List using Haskell's list operator

-- type synonym for a Linked List

type LinkedList = [Int]

front :: LinkedList -> Int                         -- front function takes a type LinkedList as input and returns an Integer, the first element of the LinkedList.
front s = head s                                   -- head returns the first element of a list in Haskell.

end :: LinkedList -> Int                           -- end function takes a type Linked List as input and returns an Integer, the last element of the LinkedList.
end s = last s                                     -- last returns the last element of a list in Haskell

ins :: Int -> LinkedList -> LinkedList             -- ins function takes a type LinkedList and an Integer as as input and returns a LinkedList with the element inserted at the end as output.
ins c s = s++[c]                                   -- the '++' operator is used to append two lists.  Here we are considering the new element as a singular list and appending it to the original one.

delete :: LinkedList -> LinkedList                 -- delete function takes a type LinkedList as input parameter and returns a LinkedList where the last element is removed.
delete s = init s                                  -- init function is used to return all but the last element of a list in Haskell.

isEmpty :: LinkedList -> Bool                      -- isEmpty function will check if the LinkedList is empty or not
isEmpty [] = True
isEmpty _ = False

showLinkedList :: LinkedList -> IO()               -- showLinkedList will output the elements of type LinkedList
showLinkedList [] = print "LinkedList empty"
showLinkedList s = print s

main = do 
	str <- getLine                                 -- Used for input for the number of operations
	let n = read str							   -- Read string as Integer
	let set = []								   -- Define an empty list which will act as a LinkedList
	action n set                                   -- Calling the loop function, passing the parameter 'set'

action 0 _ = return()
action n set = do                          
  	str <- getLine                                 -- Get the choice from the user
	let x = read str::Int
	
	if ( x == 1 )                                  -- Choice = 1 corresponds to inserting an element in the list.
	then do
		str <- getLine                             -- Get the element input from the user and convert it to an Integer
		let temp = read str::Int                   -- Call insert function
		let s1 = ins temp set
		let set = s1                               -- Since lists are immutable in Haskell, we temporarily assign it to another list and then reassign it again.
		action (n-1) set                           -- Call the loop (n-1) times while passing set as the parameter.

	else if( x==2 )                                -- Choice = 2 corresponds to deleting the last element of the list.
	then do
		let s1 = delete set                        -- Call delete function
		let set = s1
		action (n-1) set                           -- Call the loop (n-1) times while passing set as the parameter.
	
	else if( x == 3 )                              -- Choice = 3 corresponds to printing the list.
	then do
		showLinkedList set                         -- Call showLinkedList function
		action (n-1) set                           -- Call the loop (n-1) times while passing set as the parameter.

	else 
		action (n-1) set
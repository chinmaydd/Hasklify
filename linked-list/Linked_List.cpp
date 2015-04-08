# include <iostream>
# include <cstdlib>
using namespace std;

struct node                   // Structure to hold a node of the linked list. It has two data fields, value and *next.
{							  // Value is intrinsic to the node. *next is a pointer to the next node in the sequence.
	int value;
	struct node * next;
}*head;

void add_node(int val)       // Function to insert a node at the end of the linked list.
{
	node *temp = new node;
	temp -> value = val;
	temp -> next = NULL;

	if(head == NULL)
	{
		head = temp;
		return; 
	}
	else
	{
		node *current = head;
		while(current != NULL)
		{
			if(current -> next == NULL)
			{	
				current -> next = temp;
				return;
			}
			current = current -> next;
		}
	}
}

int check()                // Function to check if the linked list is empty or not.
{
	if(head == NULL)
		return 0;
	return 1;
}

void delete_node()        // Function to delete the last element of the linked list. This operation was chosen to compute the worst case complexity of the delete operation.
{
	int flag = check();
	if(flag == 0)
	{
		cout << "\nThe linked list is empty. Nothing to delete.\n";
		return;
	}
	else
	{
		node *prev = head;
		node *current = (head -> next);

		while(prev)
		{
			if(current -> next == NULL)
			{
				prev -> next = NULL;
				cout << "\nElement Deleted.\n";
				free(current);
				return;
			}
			prev = current;
			current = current -> next;
		}
	}
}

void show()                    // Function to display the entire linked list. The pointer traverses through the entire the linked list and displays the value stored in each node.
{
	node *current = head;

	int flag = check();

	if(flag == 0)
	{
		cout << "\nLinked list is empty. Nothing to show.\n";
		return;
	}

	while(current != NULL)
	{
		cout << current -> value;
		cout<<" -> ";
		current = current -> next;
	}
	cout << "X\n";
	return;
}

int main()
{	
	head = NULL;
	int choice;
	int operations;

	cin>>operations;

	while(operations--)
	{
		cout << "\n\nPlease enter one of the choices below:\n";
		cout << "1. Insert Element.\n";
		cout << "2. Delete the last element of the linked list.\n";
		cout << "3. Display the linked list.\n";
		cin>>choice;

		switch(choice)
		{
			case 1:
					int val;
					cin >> val;
					add_node(val);
					break;

			case 2: 
					delete_node();
					break;

			case 3: 
					show();
					break;
		}
	}
	return 0;
}

# include <iostream>
# include <cstdlib>
using namespace std;

struct node
{
	int value;
	struct node * next;
}*head;

void add_node(int val)
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

int check()
{
	if(head == NULL)
		return 0;
	return 1;
}

void delete_node()
{
	int flag = check();
	if(flag == 0)
	{
		// cout << "\nThe linked list is empty. Nothing to delete.\n";
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
				// cout << "\nElement Deleted.\n";
				free(current);
				return;
			}
			prev = current;
			current = current -> next;
		}
	}
}

void show()
{
	node *current = head;

	int flag = check();

	if(flag == 0)
	{
		// cout << "\nLinked list is empty. Nothing to show.\n";
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
	int noo;

	cin>>noo;

	while(noo--)
	{
		// cout << "\n\nPlease enter one of the choices below:\n";
		// cout << "1. Insert Element.\n";
		// cout << "2. Delete the last element of the linked list.\n";
		// cout << "3. Display the linked list.\n";
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

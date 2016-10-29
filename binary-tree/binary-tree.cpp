/*
C++ implementation of Binary tree Data Structure
*/
#include<iostream>
using namespace std;
// Implementation of node.
struct node {
	int value;
	node *left;
	node *right;
};
// Implementation of binary tree.
class btree {
public:
	btree();

	void insert(int key);
	void search(int key);
	void destroy_tree();
	void print_tree();
private:
	void insert(int key, node* parent);
	void search(int key, node* parent);
	void destroy_tree(node *parent);
	void print_tree(node *parent);

	node *root;
};
// Constructor function.
btree::btree()
{
	root=NULL;
}
// Method to destroy binary tree.
void btree::destroy_tree(node* parent) {
	if(parent!=NULL)
	{
		destroy_tree(parent->left);
		destroy_tree(parent->right);
		delete parent;
	}
}
// Method to insert into binary tree.
void btree::insert(int key, node* parent) {
	if(key < parent->value){
		if(parent->left!=NULL) {
			insert(key, parent->left);
		} else {
			parent->left = new node;
			parent->left->value = key;
			parent->left->left = NULL;
			parent->left->right = NULL;
		}
	}
	else if(key >= parent->value) {
		if(parent->right!= NULL) {
			insert(key, parent->right);
		} else {
			parent->right = new node;
			parent->right->value = key;
			parent->right->left = NULL;
			parent->right->right = NULL;
		}
	}
}
// Method to search in the binary tree.
void btree::search(int key, node* parent) {
	if(parent!=NULL) {
		if(parent->value == key) {
			cout<<"True"<<endl;
			return;
		} else {
			if(key < parent->value){
				search(key, parent->left);
			} else {
				search(key, parent->right);
			}
		}
	} else {
		cout<<"False"<<endl;
		return;
	}
}
// Method to print the binary tree.
void btree::print_tree(node *parent) {
	if(parent!=NULL) {
		cout<<parent->value<<"\t";
		print_tree(parent->left);
		print_tree(parent->right);
	}
}
void btree::insert(int key) {
	if(root != NULL){
		insert(key, root);
	} else {
		root = new node;
		root->value = key;
		root->left = NULL;
		root->right = NULL;
	}
}
void btree::search(int key) {
	search(key, root);
}
void btree::destroy_tree() {
	destroy_tree(root);
}
void btree::print_tree() {
	print_tree(root);
}

int main () {
	int n, i, input, option;
	btree btree;
	cout<<"Enter the number of elements:"<<endl;
	cin>>n;
	
	if(n > 0) {
		cout<<"Valid input"<<endl;
	}
	else {
		cout<<"Invalid input"<<endl;
		return 0;
	}
	cout<<"Enter the values:"<<endl;
	for(i = 0; i < n; i++) {
		cin>>input;
		btree.insert(input);
	}
	btree.print_tree();
	cout<<"What would you like to do? \n 1)Destroy \n 2) Search"<<endl;
	cin>>option;
	if(option == 1) {
		btree.destroy_tree();
		cout<<"Tree Destroyed"<<endl;
	}
	if(option == 2) {
		int search_key;
		cout<<"Enter the key:"<<endl;
		cin>>search_key;
		btree.search(search_key);
		cout<<"Search Complete"<<endl;
	}
return 0;
}
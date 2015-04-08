/*
C++ implementation of Disjoint-Set Data Structure
*/
#include<bits/stdc++.h>
using namespace std;
int fnd(int x,int set[])   //The find operation of the Data Structure
{
	if(set[x]==x)
		return x;
	else
		return set[x]=fnd(set[x],set);
}

void unin(int x,int y,int set[]) //union operation of Data Structure
{
	set[fnd(x,set)]=fnd(y,set);
}

int main()
{
	int i,j,n,m,x,y;
	cout<<"Enter the number of elements : ";
	cin>>n;
	int set[n];     //Disjoint Set
	for(i=0;i<n;i++)
		set[i]=i; //Initializing Disjoint-Set
	cout<<"Enter the number of operations : ";
	cin>>m;
	for(i=0;i<m;i++)
	{
		cout<<"Enter the two elements to do union : ";
		cin>>x>>y;
		unin(x,y,set);
		for(j=0;j<n;j++)
			cout<<set[j]<<" ";
		cout<<"\nEnter the element to do find : ";
		cin>>x;
		cout<<fnd(x,set)<<"\n";
	}
}

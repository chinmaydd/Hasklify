#include<iostream>
#include<stdlib.h>
#include<cstdlib>
using namespace std;

class queue
{
int head;
int tail;
int value;
int A[100000];
public:
void push();
void pop();
queue()
{
head=0;
tail=-1;
}
};
void queue :: push()
{
cin>>value;
A[++tail]=value;
}
void queue :: pop()
{
head++;
}





int main()
{
	int n,i;
queue S;
cin>>n;
for(i=0;i<n;i++)
 S.push();
for(i=0;i<n;i++)
 S.pop();
}

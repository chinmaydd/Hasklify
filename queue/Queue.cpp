// C++ program for implementation of queue and the various operation related to it*/
#include<iostream>
#include<stdlib.h>
using namespace std;
#define SIZE 5 
int q[SIZE],front=0,rear=0;
int main()
{
int ch;
void enqueue();
void dequeue();
void display();
while(1)
{
cout<<"\n 1. add element";
cout<<"\n 2. remove element";
cout<<"\n 3.display";
cout<<"\n 4.exit";
cout<<"\n enter your choice:";
cin>>ch;
switch(ch)
{
case 1:
/*For pushing and element at the end of the queue*/
enqueue();  
break;
case 2:
/*for removing an element from the front*/
dequeue();
break;
case 3:
/*to display the queue*/
display();
break;
case 4:
exit(0);
default:
cout<<"\n invalid choice";
}
}
return 0;
}
void enqueue()
{
int no;
if (rear==SIZE && front==0)                      /*Condition if queue is full*/
cout<<"queue is full";
else
{
cout<<"enter the num:";
cin>>no;
q[rear]=no;                                      /*The input number is added to the end of the queue*/ 
}
rear++;                                          /*rear variable incremented by one to increase queue size by one*/
}
void dequeue()
{
int no,i;
if (front==rear)                                 /*Condition if Queue is empty*/
cout<<"queue is empty";
else
{
no=q[front];                                     /*The front of the queue is copied into no*/
front++;                                         /*Increment front so that the front element is removed*/
cout<<"\n"<<no<<" -removed from the queue\n";
}
}
void display()
{
int i,temp=front;
if (front==rear)
cout<<"the queue is empty";
else
{
cout<<"\n element in the queue: ";
for(i=temp;i<rear;i++)
{
cout<<q[i]<<" ";
}
}
}

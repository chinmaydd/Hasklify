#include<iostream>
#include<stdlib.h>
#include<cstdlib>

using namespace std;

#define max 5

class stack
{
   int top;
   int value;
   int A[max];
  public:
   void push();
   void pop();
   void display();
   stack()
   {
       top=-1;
   }
};

void stack :: push()
{
  cout<<"Enter value to be pushed\n";
  cin>>value;
  if(top==max-1)
   cout<<"Stack overflow\n";
  else
   A[++top]=value;
}

void stack :: pop()
{
  if(top==-1)
   cout<<"Stack underflow\n";
  else
  {
   cout<<"popped value is "<<A[top]<<endl;
   top--;
  }
}

void stack :: display()
{
  if(top==-1)
   cout<<"Stack underflow\n";
  else
  {
   cout<<"\nStack status\n";
   for(int i=top;i>=0;i--)
    cout<<A[i]<<endl;
  }
}

int main()
{
  stack S;
  int ch;
  do
  {
  cout<<"Menu\n";
  cout<<"1.Push\n";
  cout<<"2.Pop\n";
  cout<<"3.Display\n";
  cout<<"4.Exit\n";
  cout<<"\n Enter choice\n";
  cin>>ch;
  switch(ch)
  {
    case 1:S.push();system("pause");system("cls");break;
    case 2:S.pop();system("pause");system("cls");break;
    case 3:S.display();system("pause");system("cls");break;
    case 4:exit(0);

  }
  }while(ch<=4);
  return 0;
}

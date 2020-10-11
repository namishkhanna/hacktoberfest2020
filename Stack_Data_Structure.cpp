#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
struct node                
{
 char name[20];
 int rollno,stnd;
 float perce;
 node *link;
};
class stack
{
 node *top;
 public:
  stack()
  {
   top=NULL;
  }
  void stackpush();
  void stackpop();
  void show_stack();
};
void stack::stackpush()
{
 int val;
 node *temp;
 temp=new node;
 cout<<"Enter name:";
 gets(temp->name);
 cout<<"Enter roll number:";
 cin>>temp->rollno;
 cout<<"Enter standard:";
 cin>>temp->stnd;
 cout<<"Enter percentage:";
 cin>>temp->perce;
 temp->link=NULL;
 if(top==NULL)
 {
  top=temp;
 }
 else
 {
  temp->link=top;
  top=temp;
 }
}
void stack::stackpop()
{
 node *temp;
 if(top==NULL)
 {
  cout<<"Stack Empty";
 }
 else
 {
  temp=top;
  top=top->link;
  temp->link=NULL;
  delete temp;
 }
}
void stack::show_stack()
{
 node *temp;
 temp=top;
 clrscr();
 cout<<"The values are"<<endl;
 while(temp!=NULL)
 {
  cout<<endl<<temp->name<<"\t"<<temp->rollno<<"\t"<<temp->stnd<<"\t"<<temp->perce;
  temp=temp->link;
 }
}
void main()
{
 int ch;
 stack st;
 char opt='y';
 clrscr();
 do
 {
  cout<<"Arjun Nair  XII A  Journal 19"<<endl;
  cout<<"Menu:";
  cout<<endl<<"1.Addition of stack";
  cout<<endl<<"2.Deletion from stack";
  cout<<endl<<"3.Show the stack";
  cout<<endl<<"4.Exit";
  cout<<endl<<"Enter choice ";
  cin>>ch;
  switch(ch)
  {
   case 1:
    do
    {
     st.stackpush();
     cout<<endl<<"Do you want to add more?(y/n)";
     cin>>opt;
    }
    while(opt=='y');
    break;
   case 2:
    do
    {
     clrscr();
     st.stackpop();
     cout<<endl<<"Do you want to delete more?(y/n)";
     cin>>opt;
    }
    while(opt=='y');
    break;
   case 3:
    clrscr();
    st.show_stack();
    cout<<endl;
    break;
   case 4:
    exit(0);
  }
 }
 while(ch!=4);
}



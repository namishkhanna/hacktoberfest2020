#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
struct Node
{
 string data;
 string name;
 string t;
 struct Node *next;
};
struct Node*front=NULL;
struct Node *rear=NULL;
void enqueue(string y,string w,string x)
{
 struct Node *temp;
 temp=new Node;
 if(temp==NULL)
 cout<<"Queue is FUll\n";
 else
 {
 temp->data=x;
 temp->name=y;
 temp->t=w;
 temp->next=NULL;
 if(front==NULL)
 front=rear=temp;
 else
 {
 rear->next=temp;
 rear=temp;
 }
 }
}
void dequeue()
{
 struct Node* temp;
 if(front==NULL)
 cout<<"NO Call Log";
 else
 {
 temp=front;
 front=front->next;
 free(temp);
 }
}
void display(Node *temp)
{
    if (temp == NULL)
       return;
    display(temp->next);
    cout<<temp->name<<"     "<<temp->data<<"        "<<temp->t<<endl;
    cout<<endl;
}
int main()
{
  int n,count =0;
    string x,w;
    string y;
    time_t now = time(0);
    do
    { cout<<"enter 1 for input"<<endl<<"enter 2 for output"<< endl<<"Enter 0 to exit"<<endl;
      cin>>n;
      switch(n)
      {  case 1:
           if(count >=10)
             dequeue();
           cout<<"Enter Name: ";
           cin>>x;
           cout<<"Enter Phone number :";
           cin>>y;
           w = ctime(&now);
           enqueue(x,w,y);
           count++;
           break;

           case 2:
             if(count==0)
             cout<<"No Call Log"<<endl;
             cout<<"Name\t"<<"Phone number\t\t"<<"date and time"<<endl;
             display(front);
             break;
      }
    }while(n!=0);
    return 0;
}

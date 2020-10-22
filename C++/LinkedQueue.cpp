/*
    C++ program : Queue implementation using linked list
*/

#include<bits/stdc++.h>
#include<conio.h>           //for getch()

using namespace std;

struct node
{
    int data;
    node *next;
};

class lqueue
{
    node *f, *r;
    public:
    void insertq(int);
    void deleteq();
    void displayq();
    lqueue()
    {
        f = NULL;
        r = NULL;
    }
    ~lqueue();
};

void lqueue::insertq(int i)
{
    node *ptr = NULL;
    ptr = new node;
    if(ptr == NULL)
    {
        cout<<"\nOverflow error";
        return;
    }
    cout<<"\tEnter the value#"<<i+1<<": ";
    cin>>ptr->data;
    ptr->next = NULL;
    if(f==NULL && r==NULL)
    {
        f = ptr;
        r = ptr;
    }
    else
    {
        r->next = ptr;
        r = ptr;
    }

}

void lqueue::deleteq()
{
    node *ptr=NULL;
    if(f == NULL)
        cout<<"\n\tUnderflow error";
    else
    {
        ptr=f;
        f = f->next;
        delete ptr;
    }
}

void lqueue::displayq()
{
    if(f == NULL)
    {
        cout<<"\n\tThe queue is empty.";
        return;
    }
    cout<<"\n\t";
    node *ptr = f;
    while(ptr != NULL)
    {
        cout<<ptr->data<<"-->";
        ptr=ptr->next;
    }
    cout<<"NULL";
}

lqueue::~lqueue()
{
    node *ptr=f;
    while(ptr!=NULL)
    {
        f = f->next;
        delete ptr;
        ptr = f;
    }
}

int main()
{
    lqueue q;
    int ch, n;
    while(ch!=4)
    {
        system("cls");                      //clears the screen
        cout<<"\t\t**********MENU**********\n\tBasic Queue Operations:";
        cout<<"\n\t1.Insert a node";
        cout<<"\n\t2.Delete a node";
        cout<<"\n\t3.Display queue";
        cout<<"\n\t4.Exit";
        cout<<"\n\nEnter your choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1: cout<<"\n\tHow many nodes do you want to enter: ";
                    cin>>n;
                    cout<<endl;
                    for(int i=0; i<n; i++)
                        q.insertq(i);
                    break;

            case 2: cout<<"\n\tAfter deletion, the queue:\n";
                    q.deleteq();
                    q.displayq();
                    break;

            case 3: cout<<"\n\tQueue contains:\n";
                    q.displayq();
                    break;

            case 4: exit(0);
        }
        cout<<"\nPress any key to continue...";
        getch();
    }
    return 0;
}

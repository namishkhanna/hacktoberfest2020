/*
Write a program to implement input, and output restricted deque. 
Note that deque can be input restricted or output restricted. 
It cannot be input restricted as well as output restricted at the same time. 
Your program should have the option to implement as input restricted deque or output restricted deque. Depending on the option entered by the user, 
it will execute either as input restricted deque or output restricted deque. Use a switch() statement to select the appropriate option. 
While executing as input restricted deque / output restricted deque, enter the appropriate options. 
Use a switch() statement to select the appropriate option and perform the desired action. 
Following is the illustration for input restricted deque. In an input restricted deque, 
the input to the deque can be either from the left or from the right but not at both ends. 
However, the deletion can be from both ends. Let us assume the insertion to the deque is from the left end. 
Your program while executing as input restricted deque should have the following options: Insert at left, 
Delete from left, Delete from right, Display (to display the queue content), Quit (to quit the program). 
Your program should select one of the option and using a switch() statement perform the desired operation.
Output restricted deque is analogous to input restricted deque.
*/
# include <iostream>
using namespace std;

struct node
{
    int data;
    struct node * next;
};

// function to create node
struct node * create_node ( int val )
{
    struct node * temp = new node();
    temp->data = val;
    temp->next = NULL;
    return temp;
}

// function to insert element at left of deque
void insert_at_left( struct node ** front, struct node ** rear, int val )
{
    struct node * temp = create_node( val );
    
    if(*front == NULL)
    {    
        *front = temp;
        *rear = temp;
    }
    else
    {
        temp->next = *front;
        *front = temp;
    }
}

// function to insert element at right of deque
void insert_at_right( struct node ** front, struct node ** rear, int val )
{
    struct node * temp =create_node( val );
    if(*front == NULL)
        *front = *rear = temp;
    else
    {
        (*rear)->next = temp;
        *rear =temp;
    }
}

// function to delete from left
void delete_from_left ( struct node ** front, struct node ** rear )
{
    struct node * ptr;
    if(*front ==  NULL)
        cout<<"UnderFlow\n";
    else if ( *front == *rear )
    {
        ptr = *front;
        *front = *rear = NULL;
        free(ptr);
    }
    else
    {
        ptr = *front;
        *front = (*front)->next;
        free(ptr);
    }    
}


// function to delete from right
void delete_from_right ( struct node ** front, struct node ** rear )
{
    struct node * ptr;
    if(*front ==  NULL)
        cout<<"UnderFlow\n";
    else if ( *front == *rear )
    {
        ptr = *front;
        *front = *rear = NULL;
        free(ptr);
    }
    else
    {
        ptr = *front;
        while( ptr->next->next != NULL )
        {
            ptr=ptr->next;
        }
        *rear = ptr;
        ptr = ptr->next;
        (*rear)->next = NULL;
        free(ptr); 
    }
}

// function to display
void display(struct node * front)
{
    if(front == NULL)
        cout<<"deque is empty.\n";
    else
    {
        while(front->next != NULL)
        {
            cout<<front->data<<"->";
            front = front->next;
        }
    }
    cout<<front->data<<"\n";
}
int main ()
{
    struct node * front = NULL;
    struct node * rear = NULL;
    int ch1=0, ch2, ch3, ch4, ch5;
    int value;
    char ch ='y';
    
    
    cout<<"Menu Driven Operations.\n";
    cout<<"Press 1 to use left side input restriced deque.\n";
    cout<<"Press 2 to use right side input restriced deque.\n";
    cout<<"Press 3 to use left side output restriced deque.\n";
    cout<<"Press 4 to use right side output restriced deque.\n";
    while( ch == 'Y'|| ch == 'y')
    {
        cout<<"Enter your choice for input or output restricted.\n";
        cin>>ch1;
        switch(ch1)
        {
            case 1: cout <<"\tWelcome to left-side input restricted deque.\n";
                    cout<<"\tPress 1 to perform insertion at left.\n";
                    cout<<"\tPress 2 to perform deletion from left.\n";
                    cout<<"\tPress 3 to perform deletion from right.\n";
                    cout<<"\tPress 4 to Display the contents of deque.\n";
                    cout<<"\tPress 5 to quit input restricted deque.\n";
                    do
                    {
                        cout<<"\tEnter your choice.\n";
                        cin>>ch2;
                        switch(ch2)
                        {
                            case 1: cout<<"\tEnter value to be inserted.\n";
                                    cin>>value;
                                    insert_at_left(&front, &rear, value);
                                    break;
                            case 2: delete_from_left(&front, &rear);
                                    break;
                            case 3: delete_from_right(&front, &rear);
                                break;
                            case 4: cout<<"\t";
                                    display(front);
                                    break;
                            case 5: break;
                            default:cout<<"\tWrong choice Entered re-enter your choice.\n";
                     }
                    } while (ch2 != 5);
                    break;
            case 2: cout <<"\tWelcome to right-side input restricted deque.\n";
                    cout<<"\tPress 1 to perform insertion at right.\n";
                    cout<<"\tPress 2 to perform deletion from left.\n";
                    cout<<"\tPress 3 to perform deletion from right.\n";
                    cout<<"\tPress 4 to Display the contents of deque.\n";
                    cout<<"\tPress 5 to quit input restricted deque.\n";
                    do
                    {
                        cout<<"\tEnter your choice.\n";
                        cin>>ch3;
                        switch(ch3)
                        {
                            case 1: cout<<"\tEnter value to be inserted.\n";
                                    cin>>value;
                                    insert_at_right(&front, &rear, value);
                                    break;
                            case 2: delete_from_left(&front, &rear);
                                    break;
                            case 3: delete_from_right(&front, &rear);
                                   break;
                            case 4: cout<<"\t";
                                    display(front);
                                    break;
                            case 5: break;
                            default:cout<<"Wrong choice Entered re-enter your choice.\n";
                        }
                    } while (ch3 != 5);
                    break;
            case 3: cout <<"\tWelcome to left-side output restricted deque.\n";
                    cout<<"\tPress 1 to perform insertion at left.\n";
                    cout<<"\tPress 2 to perform insertion at right.\n";
                    cout<<"\tPress 3 to perform deletion from left.\n";
                    cout<<"\tPress 4 to Display the contents of deque.\n";
                    cout<<"\tPress 5 to quit input restricted deque.\n";
                    do
                    {
                        cout<<"\tEnter your choice.\n";
                        cin>>ch4;
                        switch(ch4)
                        {
                            case 1: cout<<"\tEnter value to be inserted at left.\n";
                                    cin>>value;
                                    insert_at_left(&front, &rear, value);
                                    break;
                            case 2: cout<<"\tEnter value to be inserted at right.\n";
                                    cin>>value;
                                    insert_at_right(&front, &rear, value);
                                    break;
                            case 3: delete_from_left(&front, &rear);
                                    break;
                            case 4: cout<<"\t";
                                    display(front);
                                    break;
                            case 5: break;
                            default:cout<<"Wrong choice Entered re-enter your choice.\n";
                        }
                    } while (ch4 != 5);
                    break;
            case 4: cout <<"\tWelcome to right-side output restricted deque.\n";
                    cout<<"\tPress 1 to perform insertion at left.\n";
                    cout<<"\tPress 2 to perform insertion at right.\n";
                    cout<<"\tPress 3 to perform deletion from right.\n";
                    cout<<"\tPress 4 to Display the contents of deque.\n";
                    cout<<"\tPress 5 to quit input restricted deque.\n";
                    do
                    {
                        cout<<"\tEnter your choice.\n";
                        cin>>ch5;
                        switch(ch5)
                        {
                            case 1: cout<<"\tEnter value to be inserted at left.\n";
                                    cin>>value;
                                    insert_at_left(&front, &rear, value);
                                    break;
                            case 2: cout<<"\tEnter value to be inserted at right.\n";
                                    cin>>value;
                                    insert_at_right(&front, &rear, value);
                                    break;
                            case 3: delete_from_right(&front, &rear);
                                    break;
                            case 4: cout<<"\t";
                                    display(front);
                                    break;
                            case 5: break;
                            default:cout<<"Wrong choice Entered re-enter your choice.\n";
                        }
                    } while (ch5 != 5);
                    break;
            default:cout<<"\tWrong choice entered.\n";           
        }
        cout<<"Do you want to continue operations in input or output restricted deque.\n";
        cout<<"Enter y for yes or n for no.\n";
        cin>>ch;
    }            
        
    return 0;
}

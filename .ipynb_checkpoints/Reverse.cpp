#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
};

void reverse(Node **Start)
{
    Node *temp = NULL;
    Node *current = *Start;

    while (current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;

        if (temp != NULL)
        {
            *Start = temp->prev;
        }
    }
}
void push(Node **Start, int value)
{

    Node *another_Node = new Node();
    another_Node->data = value;
    another_Node->prev = NULL;
    another_Node->next = *Start;

    if ((*Start) != NULL)
    {
        (*Start)->prev = another_Node;
        (*Start) = another_Node;
    }
}
void PrintList(Node *Temper)
{
    while (Temper != NULL)
    {
        cout << Temper->data << "--";

        Temper = Temper->next;
    }
}
int main()
{
    Node *head = NULL;

    push(&head, 8);
    push(&head, 10);
    push(&head, 14);

    cout << "The list is given as" << endl;
    PrintList(head);

    reverse(&head);

    cout << "The  reverse list is given as" << endl;
    PrintList(head);
}

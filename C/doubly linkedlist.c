#include<stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
    struct node* prev;
};

struct node* head = NULL;

struct node* newNode(int a)
{
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->data = a;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

void InsertatBeg(int a){
    struct node* temp = newNode(a);
    if(head == NULL)
    {
        head = temp;
        return;
    }
    temp->next = head;
    head->prev = temp;
    head = temp;
}

void Print()
{
    if(head == NULL)
    {
        return;
    }
    struct node* temp = head;
    while(temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp = temp->next;
    }
}

void ReversePrint()
{
    if(head == NULL)
    {
        return;
    }
    struct node* temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    while(temp != NULL)
    {
        printf("%d\n",temp->data);
        temp = temp->prev;
    }
}

int main()
{
    InsertatBeg(2);
    InsertatBeg(4);
    InsertatBeg(6);
    InsertatBeg(8);
    Print();
    ReversePrint();
}
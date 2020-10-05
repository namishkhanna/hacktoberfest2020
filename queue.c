#include<stdio.h>
#include<stdlib.h>
 
struct Queue{
    int size;
    int front;
    int rear;
    int *arr;
};

int isFull(struct Queue *q){
    if(q->rear == q->size - 1)
        return 1;
    else
        return 0;
}
int isEmpty(struct Queue *q){
    if(q->rear == q->front)
        return 1;
    else
        return 0;
}

void push(struct Queue *q,int data){
    if(isFull(q))
        printf("Queue Overflow\n");
    else{
        q->rear = q->rear ++;
        q->arr[q->rear] = data;
    }
}

int pop(struct Queue *q){
    int a = -1; 
    if(isEmpty(q))
        printf("Queue Underflow!\n");
    else{
        q->front++;
        a = q->arr[q->front];
    }
    return a;
}

int peek(struct Queue *q,int i){
    int pos = q->rear-i+1;
    if(pos<0)
        printf("Invalid Position\n");
    else
        return q->arr[pos];
}

int main()
{
    struct Queue *q; 
    q->size = 50;
    q->front = q->rear = -1; //initially it's empty
    q->arr = (int *) malloc (q->size * sizeof(int));

    push(q,20);
    push(q,46);
    push(q,75);

    for (int j = 1; j <= q->rear+1; j++)
        printf("The value at index %d is %d\n",j,peek(q,j));
    

    return 0;
}

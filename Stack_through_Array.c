#include<stdio.h>
#include <stdlib.h>
#define Max 100
int top = -1;
int Arr[Max];

void Push(int a){
    if(top >= Max - 1){
        printf("Stack Overflow\n"); return;
    }
    Arr[++top] = a;
}

void Pop(){
    if(top == -1){
        printf("Stack is Empty\n");
    }
    top--;
}

int Top(){
    return Arr[top];
}

void Print(){
    for(int i=0;i<=top;i++)
    {
        printf("%d\n",Arr[i]);
    }
}

int main(){
    Push(2);
    Push(3);
    Push(4);
    Print();
}
//wadhiyamansi@gmail.com  aloo16#
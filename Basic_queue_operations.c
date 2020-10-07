#include <stdio.h>
#define max 5

int queue[max];
int front=-1,rear=-1;

void enqueue(){
	int data;
	printf ("Enter the element to be added\n");
	scanf ("%d", &data);
	if(rear==max-1){
		printf("Overflow");
	}else if(rear==-1 && front==-1){
		rear=front=0;
		queue[rear]=data;
	}else{
		rear++;
		queue[rear]=data;
	}
}

int dequeue(){
	if((front==-1 && rear ==-1 )|| front> rear){
		printf("underflow");
	}else{
		return queue[front++];
	}
}

void display(){
	if((front==-1 && rear ==-1 )|| front> rear){
		printf("underflow");
	}else{
		int i;
		printf("\n");
		for(i=front;i<=rear;i++){
			printf("%d ",queue[i]);
		}
	}
}


int main ()
{
int choice;
int option = 1;
printf ("QUEUE OPERATION\n");
while (option)
{
printf ("------------------------------------------\n");
printf (" 1 --> ENQUEUE \n");
printf (" 2 --> DEQUEUE \n");
printf (" 3 --> DISPLAY \n");
printf (" 4 --> EXIT \n");
printf ("------------------------------------------\n");

printf ("Enter your choice\n");
scanf ("%d", &choice);

switch (choice)
{
case 1: enqueue();
break;
case 2: dequeue();
break;
case 3: display();
break;
case 4: return;
}

fflush (stdin);
printf ("Do you want to continue(Type 0 or 1)?\n");
scanf ("%d", &option);
}
return 0;
}



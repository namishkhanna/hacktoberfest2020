#include<stdio.h>
void main()
{
int i,j,x;
printf("Enter value of X....");
scanf("%d",&x);
for(i=1;i<=x;i++)
    {
        for(j=1;j<=i;j++)
           printf("*");
    printf("\n");

    }
}

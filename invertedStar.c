#include<stdio.h>
void main()
{
    int i,j,x;
    printf("Enter the value of X....");
    scanf("%d",&x);
    for(i=1;i<=x;i++)
    {
        for(j=i;j<=x;j++)
            printf("*");
        printf("\n");
    }

}

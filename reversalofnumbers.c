#include <stdio.h>
int main()
{
    int a;
    printf("enter a two digit number: ");
    scanf ("%d", &a);
    printf("The reversal is: %d%d\n",a%10,a/10 );
}
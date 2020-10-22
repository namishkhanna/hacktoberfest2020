#include <stdio.h>
int main()
{
    int h,m;
    printf("Enter a 24 hour time: ");
    scanf("%d:%d", &h,&m);
    if (h!=12)
        h-=12;
    printf("Equivalent 12 hour time: %d:%d PM\n",h,m);
}
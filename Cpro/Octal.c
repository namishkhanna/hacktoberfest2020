#include <stdio.h>

int main()
{
    int n, a1, a2, a3, a4, a5;
    printf("Enter a number between 0 and 32767: ");
    scanf("%d", &n);

    a1 = n % 8;
    a2 = (n / 8) % 8;
    a3 = ((n / 8) / 8) % 8;
    a4 = (((n / 8) / 8) / 8) % 8;
    a5 = ((((n / 8) / 8) / 8) / 8) % 8;

    printf("In octal, your number is: %d%d%d%d%d \n",a5,a4,a3,a2,a1);

    return 0;
}

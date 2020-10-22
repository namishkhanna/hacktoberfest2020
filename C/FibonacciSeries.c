#include <stdio.h>

 

void main()

{

      int f1 = 0, f2 = 1, f3, n;

      printf("Program for Fibonacci Series\n");

      printf("Enter the maximum number for Fibonacci Series: ");

      scanf("%d", &n);

      printf("\nPrinting Fibonacci Series from 0 - %d\n", n);

      printf("%d\n%d\n", f1, f2);

      while(1)

      {

            f3 = f1 + f2;

            if(f3 > n)

                  break;

            printf("%d\n", f3);

            f1 = f2;

            f2 = f3;

      }

}

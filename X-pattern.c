#include<stdio.h>
#include<string.h>
int main()
{
	 int i,j,k,l;
	 char a[100];
	 printf("Enter a string:");
	 gets(a);
   
   #printing in X pattern
   
	 for(i=0;i<strlen(a);i++)
	 {
	 	for(j=0;j<=(strlen(a)-1);j++)
	 	{
	 	      if(i==j)
	 		{
	 			printf(" %c",a[i]);
			 }
			 else if(j==strlen(a)-(i+1))
			 {
			 	printf(" %c",a[j]);
			 }
			else{
			 	printf("  ");
			 }
		 }
		 printf("\n");
	 }
}

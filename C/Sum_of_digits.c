#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	
    int n;
    int sum=0,m;
    printf("Enter Number:");
    scanf("%d", &n);
    while(n>0){
	m = n%10;
	sum = sum + m;
	n = n/10;  
}
    printf("%d\n",sum);
    return 0;
}

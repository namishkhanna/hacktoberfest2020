#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int t;
	int x=1; 
	int a[10]; 
    scanf("%d",&t);
    for(int a0 = 0; a0 < t; a0++){
        int n; 
        scanf("%d",&n);
		if(n==0)
		a[a0]=x;
		else if(n%2==0)
		{
			while(n!=0){
		   x=2*x+1;
		   n-=2;
		  	 }
		 }
		else{
		while(n!=1){
		x=2*x+1;
		n-=2;
		}
		if(n==1){
		x=2*x;
		}
		
		}
		    
        
        a[a0]=x;
		x=1;
    }
	for(int a0 = 0; a0 < t; a0++){
		printf("%d\n",a[a0]);
	}
    return 0;
}

#include <stdio.h>
#include <math.h>

int main() {
    int n1,n2;
    char op;
    
   
    printf("Enter two numbers \n");
    scanf("%d %d",&n1,&n2);
     fflush(stdin);
      printf("Enter the operator \n ");
    scanf("%c",&op);
    
    
    
    switch(op){
        case '+' : printf(" %d %c %d = %d \n", n1,op,n2,n1+n2);
            break;
        case '-' : printf(" %d %c %d = %d \n", n1,op,n2,n1-n2);
            break;
        case '/' : printf(" %d %c %d = %d \n", n1,op,n2,n1/n2);
            break;
        case '*' : printf(" %d %c %d = %d \n", n1,op,n2,n1*n2);
        break;
            
        default: printf("Enter a valid operator \n");
            break;
    }
  
    
    return 0;
}



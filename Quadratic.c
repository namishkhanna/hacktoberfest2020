#include <stdio.h>
#include <math.h>

int main() {
    printf("Enter the constants for the required quadratic eqn - \n");
    int a,b,c,t;
    scanf("%d %d %d",&a,&b,&c);
    float x,y,d;
    
    t= pow(b,2)- 4*a*c;
    d= sqrt(t);
    
    x = (-b + d)/2*a ;
    y = (-b - d)/2*a ;
    
    switch(t>0){
        case 0: ;
            break;
        case 1:  printf("The Roots of the quadratic Equation are- %f %f \n" , x ,y );
            break;
        default: ;
    }
    
    switch(t==0){
        case 0: ;
            break;
        case 1:  printf("The roots are equal, havin the value: %f \n" , x);
            break;
        default: ;
    }
    
    switch(t<0){
        case 0: ;
            break;
        case 1: printf("The roots are non- Real \n");
            break;
        default: ;
    }

    return 0;
}


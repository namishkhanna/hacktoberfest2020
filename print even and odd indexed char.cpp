#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
   
    int T;
    char S[10000];
    scanf("%d", &T);
    for(int i = 0; i < T; i++)
    {
        scanf("%s", S);
        for(int j = 0; j < strlen(S); j++){
            if(j % 2 == 0){
                printf("%c", S[j]);
            }
        }
        printf(" ");    
        for(int j = 0; j < strlen(S); j++){
            if(j % 2 != 0){
                printf("%c", S[j]);
            }
        }
    printf("\n");
    }
    return 0;
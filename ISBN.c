#include <stdio.h>

int main()
{
    int gsi, gi, pc, in, c;
    printf("Enter ISBN: ");
    scanf("%d-%d-%d-%d-%d", &gsi, &gi, &pc, &in, &c);

    printf("GSI prefix: %d \n", gsi);
    printf("Group identifier: %d \n", gi);
    printf("Publisher code: %d \n", pc);
    printf("Item number: %d \n", in);
    printf("Check digit: %d \n", c);

    return 0;
}
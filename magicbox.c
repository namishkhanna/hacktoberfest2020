#include <stdio.h>

int main()
{
    int i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14, i15, i16;
    int r1, r2, r3, r4, c1, c2, c3, c4, d1, d2;

    printf("Enter the numbers from 1 to 16 in any order: ");
    scanf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d", &i1, &i2, &i3, &i4, &i5, &i6, &i7, &i8, &i9, &i10, &i11, &i12, &i13, &i14, &i15, &i16);

    r1 = i16 + i3 + i2 + i13;
    r2 = i5 + i10 + i11 + i8;
    r3 = i9 + i6 + i7 + i12;
    r4 = i4 + i15 + i14 + i1;
    c1 = i16 + i5 + i9 + i4;
    c2 = i3 + i10 + i6 + i15;
    c3 = i2 + i11 + i7 + i14;
    c4 = i13 + i8 + i12 + i1;
    d1 = i16 + i10 + i7 + i1;
    d2 = i4 + i6 + i11 + i13;

    printf("%d\t%d\t%d\t%d \n", i16, i3, i2, i13);
    printf("%d\t%d\t%d\t%d \n", i5, i10, i11, i8);
    printf("%d\t%d\t%d\t%d \n", i9, i6, i7, i12);
    printf("%d\t%d\t%d\t%d \n", i4, i15, i14, i1);

    printf("Row sums: %d  %d  %d  %d \n", r1, r2, r3, r4);
    printf("Cloumn sums: %d  %d  %d  %d \n", c1, c2, c3, c4);
    printf("Diagonal sums: %d  %d \n", d1, d2);

    return 0;
}
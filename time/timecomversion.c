#include <stdio.h>

int main()
{
    int hr, min;

    printf("Enter a 24-hour time: ");
    scanf("%d:%d", &hr, &min);

    if (hr > 12)
        printf("Equivalent 12-hour time: %d:%d PM \n", hr - 12, min);
    else if (hr == 12 && min == 0)
    {
        printf("Equivalent 12-hour time: 12:00 PM \n");
    }
    else if (hr == 0 && min == 0)
    {
        printf("Equivalent 12-hour time: 12:00 AM \n");
    }
    else
    {
        printf("Equivalent 12-hour time: %d:%d AM \n", hr, min);
    }

    return 0;
}

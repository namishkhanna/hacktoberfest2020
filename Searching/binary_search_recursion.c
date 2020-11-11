// C Program to search for an element using binary search recursively

#include<stdio.h>
#include<stdlib.h>

void binarySearch(int *a, int lb, int ub, int key)
{
    int mid;
    if (lb > ub)
    {
        printf("Element not found\n");
        return -1;
    }
    mid = (lb + ub) / 2;
    if (a[mid] == key)
    {
        printf("\nElement %d found at index %d",a[mid],mid);
    }
    else if (a[mid] > key)
        binarySearch(a, lb, mid - 1, key);
    else if (a[mid] < key)
        binarySearch(a, mid + 1, ub, key);
}

int main()
{
    int i,n,a=0;
	printf("Enter the length of an array: ");
	scanf("%d",&n);
	int *arr;
	arr = (int*)malloc(n*sizeof(int));
	printf("\nEnter the value in ascending order: ");
	for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
	printf("\nEnter the number to be searched: ");
	scanf("%d",&a);
	binarySearch(arr,0,n,a);
}

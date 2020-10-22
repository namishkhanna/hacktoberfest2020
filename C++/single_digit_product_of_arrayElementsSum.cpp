//Create a function that takes an array of numbers as arguments, adds them together, and returns the product of digits until the answer is only 1 digit long.
//Hint 1. sumDigProd([16, 28]) ➞ 6 16 + 28 = 44 4 * 4 = 16 1 * 6 = 6 2. sumDigProd([1, 2, 3, 4, 5, 6]) ➞ 2

#include<bits/stdc++.h>
using namespace std;

int sumDig(int a[], int n)
{
int sum=0;
int prod=1;
for(int i=0;i<n;i++){
sum+=a[i];
}
return sum;
}
 
int repeatedProduct(int n) 
{ 
    int prod = 1; 
        while (n > 0 || prod > 9) { 
            if (n == 0) { 
            n = prod; 
            prod = 1; 
        } 
        prod *= n % 10; 
        n /= 10; 
    } 
    return prod; 
} 

int main()
{
int a[50];
int n;
cout<<"Enter the number of values:";
cin>>n;
for(int i =0;i<n;i++){
cin>>a[i];
}
cout<<"The single digit product of the sum of the elements is "<<repeatedProduct(sumDig(a,n));
return 0;
}
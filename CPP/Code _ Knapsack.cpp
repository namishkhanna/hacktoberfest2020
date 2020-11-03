Code : Knapsack
Send Feedback
A thief robbing a store and can carry a maximal weight of W into his knapsack. There are N items and ith item weigh wi and is value vi. What is the maximum value V, that thief can take ?
Input Format :
Line 1 : N i.e. number of items
Line 2 : N Integers i.e. weights of items separated by space
Line 3 : N Integers i.e. values of items separated by space
Line 4 : Integer W i.e. maximum weight thief can carry
Output Format :
Line 1 : Maximum value V
Constraints
1 <= N <= 20
1<= wi <= 100
1 <= vi <= 100
Sample Input 1 :
4
1 2 4 5
5 4 8 6
5
Sample Output :
13




















				PRACTICE
#include <iostream>
using namespace std;
int knapsack(int* weights, int* values, int n, int maxWeight){

	/* Don't write main().
	*  Don't read input, it is passed as function argument.
	*  Return output and don't print it.
	*  Taking input and printing output is handled automatically.
	*/

	//write your code here

}


				SOLUTION





#include<bits/stdc++.h>
int newKnapsack(int *weights,int *values,int n,int maxWeight){
    int *output=new int[maxWeight+1];
    for(int i=0;i<n;i++){
        for(int j=maxWeight;j>=weights[i];j--){
            output[j]=max(output[j],values[i]+output[j-weights[i]]);
        }
    }
    return output[maxWeight];
}
int knapsack(int* weights, int* values, int n, int maxWeight){
return newKnapsack(weights,values,n,maxWeight);






#include "solution.h"

int main() {
	int n; 
	cin >> n;
	int* weights = new int[n];
	int* values = new int[n];

	for(int i = 0; i < n; i++){
		cin >> weights[i];
	}

	for(int i = 0; i < n; i++){
		cin >> values[i];
	}

	int maxWeight;
	cin >> maxWeight;

	cout << knapsack(weights, values, n, maxWeight) << endl;
}









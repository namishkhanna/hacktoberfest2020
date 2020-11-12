#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

void knapsack(int weight[], int value[], int numberOfItems, int bagCapacity){

	int dp[MAX][MAX];

	for(int i = 0; i <= numberOfItems; i++){ 
		for(int j = 0; j <= bagCapacity; j++){ 
			if(i == 0 || j == 0)
				dp[i][j]=0; 
			else if (weight[i-1] <= j)
				dp[i][j] = max(value[i-1] + dp[i-1][j-weight[i-1]], dp[i-1][j]); 
			else
				dp[i][j] = dp[i-1][j];
		}
	}

	printf("%d\n",dp[numberOfItems][bagCapacity]);
}

int main(){

	int numberOfItems = 3, bagCapacity = 50;

	int weight[] = {10, 20, 30};
	int value[] = {60, 100, 120};
	
	knapsack(weight, value, numberOfItems, bagCapacity);

	return 0;
}

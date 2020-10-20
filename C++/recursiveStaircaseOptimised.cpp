#include<iostream>
using namespace std;
/*

very bad Time complxity O(3^n);
long long int countStaircases(int n){

    if(n == 0)return 1;

    if(n < =) return 0;

    return countStaircases(n-1)+countStaircases(n-2)+countStaircases(n-3);

}  */


/*
Using Memoization 
long long int countStaircases(int n, int *dp){

    if(n == 0)return 1;
    
    if(n < =) return 0;

    if(dp[n] > 0)return dp[n];

    dp[n] = countStaircases(n-1)+countStaircases(n-2)+countStaircases(n-3);

    return dp[n];
} 
 */



// Using tabulation method

int countStairs(int n){
    int dp[n+1] = {0};      //Assigning some storage

    dp[0] = 1;             //Giving some meaning

    for(int i=1;i<=n;i++){                  //Direction of problem from small to high
        if(i == 1)dp[i] = dp[i-1];
        else if(i == 2)dp[i] = dp[i-1]+dp[i-2];
        else dp[i] = dp[i-1]+dp[i-2]+dp[i-3];
    }

    return dp[n];
}


int main(){

    int n;
    cin>>n;
    int arr[n+1] = {0};
    cout << countStairs(n);

}
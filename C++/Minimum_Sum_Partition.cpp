#include<bits/stdc++.h>
using namespace std;

int solve(int arr[],int n,int range)
{
    bool dp[n+1][range+1];
    memset(dp,false,sizeof(dp));
    
    for(int i=0;i<=n;i++)
        dp[i][0] = true;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=range;j++)
        {
            if(arr[i-1]<=j)
                dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    
    int mn = INT_MAX;
    for(int i=0;i<=range/2;i++)
    {   if(dp[n][i]==true)
        {
            mn = min(mn,abs(range-2*i));
        }
    }
    return mn;
}

int main() {
	
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;

    int arr[n];
    int sum =0;

    cout<<"Enter the elements: ";
    for(int i=0;i<n;i++)
    {    cin>>arr[i];
         sum+= arr[i];   
    }     

    int ans = solve(arr,n,sum);

    cout<<"Mininum absolute difference between two sum partitions: "<<ans<<endl;
	
	return 0;
}
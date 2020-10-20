#include<iostream>
using namespace std;
int bottomup(int *price,int *weight,int n,int cap)
{
    int dp[1000][1000]={0};
    for (int N = 1; N <= n; N++)
    {
        for (int capacity = 1; capacity <= cap; capacity++)
        {
            int inc=0,exc=0;
            if (capacity >= weight[N-1])
            {
                inc = price[N-1] + dp[N-1][capacity - weight[N-1]];
            }
            exc = 0 + dp[N-1][capacity];
            dp[N][capacity] = max(inc,exc);
        }
        
    }
    return dp[n][cap];
}
int main()
{
    int n,k,weight[1000],price[1000];
    cin>>n>>k;
    for (int i = 0; i < n; i++)
    {
        cin>>weight[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin>>price[i];
    }
    cout<<bottomup(price,weight,n,k);
    return 0;
}


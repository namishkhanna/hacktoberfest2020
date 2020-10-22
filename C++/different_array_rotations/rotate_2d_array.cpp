#include<iostream>
using namespace std;
int main()
{
	int T;   //test cases
	cin>>T;
	for(int x=0; x<T; x++)
	{
		int n, i, j;     //array size
		cin>>n;
		int arr[n][n];
		for(i=0;i<n;i++)
	    {
	        for(j=0;j<n;j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    for(i=0; i<n; i++)
	    {
	    	for(j=i; j<n; j++)
	    	{
	    		int temp=arr[i][j];
	    		arr[i][j]=arr[j][i];
	    		arr[j][i]=temp;
			}
		}
		for(i=0; i<n; i++)
		{
			for(j=n-1; j>=0; j--)
			{
				cout<<arr[i][j]<<" ";
			}
		}
		cout<<"\n";
	}
}

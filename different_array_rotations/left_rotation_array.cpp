#include<iostream>
using namespace std;
int main()
{
		int n;
		int r;
		cin>>n>>r;
		int arr[n];
		for(int i=0; i<n; i++)
		{
			cin>>arr[i];
		}
		int k=arr[0];
		for(int i=0; i<r; i++)
		{
			for(int j=0; j<n; j++)
			{
				arr[j]=arr[j+1];
			}
			arr[n-1]=k;
			k=arr[0];
		}
		for(int i=0; i<n; i++)
		{
			cout<<arr[i]<<" ";
		}
}

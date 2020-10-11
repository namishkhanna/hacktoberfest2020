#include <iostream>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n, d;
	    cin>>n;
	    int arr[n];
	    for(int i=0; i<n; i++)
	    {
	        cin>>arr[i];
	    }
	    cin>>d;
	    for(int j=d; j<n; j++)
	    {
	    	cout<<arr[j]<<" ";
		}
		for(int k=0; k<d; k++)
		{
			cout<<arr[k]<<" ";
		}
		cout<<endl;
	}
}

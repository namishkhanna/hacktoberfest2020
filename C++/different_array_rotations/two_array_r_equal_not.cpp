#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int t, f=0;
	cin>>t;
	while(t--)
	{
		int f=0;
		long long int n;
		cin>>n;
		long long int a[n];
		long long int b[n];
		for(int i=0; i<n; i++)
		{
			cin>>a[i];
		}
		for(int i=0; i<n; i++)
		{
			cin>>b[i];
		}
		sort(a, a+n);
		sort(b, b+n);
	//	for(int i=0; i<n; i++)
	//	{
	//		cout<<a[i]<<" "<<b[i]<<endl;
	//	}
		for(int i=0; i<n; i++)
		{
			if(a[i]==b[i])
			f=1;
			else
			{
				f=0;
				break;
			}
		}
		(f==1)?cout<<"1"<<endl:cout<<"0"<<endl;
	}
}

		

//Longest Common Subsequence in two given strings
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,i,j,k,a,b;
	cout<<"Enter the size of strings\n";
	cin>>n>>m;
	char M[n+1],F[m+1];
	M[0]='0';
	F[0]='0';
	cout<<"Enter the first string \n";
	for(i=1;i<n+1;i++)
	cin>>M[i];
	cout<<"Enter the second string \n";
	for(i=1;i<m+1;i++)
	cin>>F[i];
	int A[n+1][m+1]={0};
		for(i=0;i<=n;i++)
	{
		for(j=0;j<=m;j++)
		A[i][j]=0;
	}
	for(i=1;i<n+1;i++)
	{
		for(j=1;j<m+1;j++)
		{
			a=i-1;
			b=j-1;
			if(M[i]==F[j])
			{
				A[i][j]=A[a][b]+1;
			}
			else
			{
				A[i][j]=max(A[i][b],A[a][j]);
			}
		}
	}
	cout<<A[n][m];
}

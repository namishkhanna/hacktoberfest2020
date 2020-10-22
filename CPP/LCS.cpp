#include <iostream>
using namespace std;

string LCS(string A,string B, int n, int m)
{
    int t[n+1][m+1]; int maxi = 0, I , J;
    for(int i=0;i<=n;i++)
    for(int j=0;j<=m;j++)
    if(i==0 || j==0)
    t[i][j]=0;
    
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    {
        if(A[i-1]==B[j-1])
        t[i][j] = 1 + t[i-1][j-1];
        else
        t[i][j] = 0;
        if(maxi<t[i][j]){
        maxi = t[i][j];
        I = i; J = j;}
    }
    
    // for(int i=0;i<=n;i++){
    // for(int j=0;j<=m;j++){
    // cout<<t[i][j]<<" ";}cout<<endl;}
    // cout<<I<<" "<<J<<endl;
    
    string res ="";
    int i = I; int j = J;
   
    while(t[i][j]>0)
    {
        res.push_back(A[i-1]);
        i--;j--;
       
    }
    if (res.length() == 2 ){
        if(res[0]==res[1])
            return res ;
        else {
            res = A[0];return res;}}
    return res;
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    string A,B;
	    cin>>B;
	    A = B;
	    reverse(B.begin(),B.end());
	    int n = A.length();
	    int m = n;
	    cout<<LCS(A,B,n,m)<<endl;
	}
	return 0;
}

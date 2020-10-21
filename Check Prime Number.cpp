#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
ios::sync_with_stdio(false);
ll n;
cin >> n;
ll i;
bool flag=false;
for(i=2;i<=sqrt(n);i++)
{
if(n%i==0)
{
flag=true;
break;
}
}
if(flag)
cout << "composite\n";
else
cout << "prime\n";
}

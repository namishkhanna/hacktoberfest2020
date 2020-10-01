#include<bits/stdc++.h>
using namespace std;
//c++ code to calculate gcd of two numbers
int gcd(int a,int b)
{
    if(b==0)
        return a;
    gcd(b,a%b);
}
int main()
{
    int a,b;
    cin>>a>>b;
    cout<<"gcd of a and b is :"<<" "<<gcd(a,b)<<"\n";
    return 0;
}
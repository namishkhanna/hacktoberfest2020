#include<bits/stdc++.h>

using namespace std;

int printFibo(int n)
{
   if ( n == 0 )
      return 0;
   else if ( n == 1 )
      return 1;
   else
      return ( printFibo(n-1) + printFibo(n-2) );
} 
 
int main()
{
   int n, i = 0;
 
   cin>>n;
 
   cout<<"Fibonacci series\n";
 
   for (int c = 1 ; c <= n ; c++ )
   {
      cout<<printFibo(i)<<" ";
      i++; 
   }
 
   return 0;
}

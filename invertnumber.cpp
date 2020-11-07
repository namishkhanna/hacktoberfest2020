/// NICOI ALEXANDRU - tr0yyy
/// Invert number cpp

#include <iostream>

using namespace std;

long x,im,c;
int main()
{
    cin>>x;
    im=0;
    while(x!=0)
    {
        c=x%10;
        x=x/10;
        im=im*10+c;
    }
    cout<<im;
}

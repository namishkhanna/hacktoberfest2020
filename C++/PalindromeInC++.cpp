#include <iostream>
using namespace std;

int main()
{
    long long int a,b,num;
    char key;
    X:
    cout << "Enter number to check palindrome: ";
    cin>>num;
    a=num;
    b=0;

    while(a!=0)
    {
        b=b*10+(a%10);
        a=a/10;
    }
    if(num==b)
    {
        cout<<"Number "<<num<<" is a palindrome"<<endl;
        cout << "----------------------------------------"<<endl;
    }
    else
    {
        cout<<"Number "<<num<<" is not a palindrome"<<endl;
        cout << "----------------------------------------"<<endl;
    }
    Y:
    cout<<"\nPress S to check more or Press E to exit :";
    cin>>key;
    if(toupper(key)=='E')
    {
        exit(0);
    }
    else if(toupper(key)=='S')
    {
        goto X;
    }
    else
    {
        goto Y;
    }

    return 0;
}

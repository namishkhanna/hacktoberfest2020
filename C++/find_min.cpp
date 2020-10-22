#include <iostream>
using namespace std;

int main()
{
    int i, n, min, arr[1000];
    cout << "Enter total numbers: ";
    cin >> n;
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    min = arr[0];
    for(i=1;i<n;i++)
    {
        if(arr[i]<min)
        {
            min = arr[i];
        }
        else
        {
            min = min;
        }
    }
    cout<<min;
    return 0;
}

#include <iostream>
using namespace std;

int main()
{
    int i, n, max, final_max, arr[1000];
    cout << "Enter total numbers: ";
    cin >> n;
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    max = arr[0];
    for(i=1;i<n;i++)
    {
        if(arr[i]>max)
        {
            max = arr[i];
        }
        else
        {
            max = max;
        }
    }
    cout<<max;
    return 0;
}

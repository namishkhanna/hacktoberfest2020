#include <iostream>
#include<algorithm>
using namespace std;

#define OJ                            \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

int main()
{
   // OJ;
    long long int n;
    cin >> n;
    long long int* arr = new long long int[n];
    for(long long int i=0; i<n ;i++){
        cin >> arr[i];
    }

    sort(arr, arr+n);
    long long int mid = n/2;
    long long int cost = 0;
    for(long long int i=0; i<n; i++){
        cost += abs(arr[i]- arr[mid]);
    }

    cout << cost << endl;

    return 0;
}

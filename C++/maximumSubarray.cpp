#include <iostream>
#include<climits>
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
    //OJ;
    long long int n;
    cin >> n;
    long long int* arr = new long long int[n];
    for(long long int i=0; i<n; i++){
        cin >> arr[i];
    }
    long long int sum = INT_MIN;
    long long int count = 0;
    long long int i =0 ;
    while(i<n){
        count += arr[i]; 
        if (sum < count) 
            sum = count; 
  
        if (count < 0) 
            count = 0; 

        i++;
    }

    cout << sum << endl;

    return 0;
}
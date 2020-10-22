#include <iostream>
#include<map>
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
    OJ;
    FIO;
    long long int n;
    cin >> n;
    long long int* arrival = new long long int[n];
    long long int* departure = new long long int[n];
    for(long long int i=0; i<n; i++){
        cin >> arrival[i] >> departure[i];
    }

    sort(arrival, arrival+n);
    sort(departure, departure+n);

    for(long long int i=0; i<n; i++){
        cout << arrival[i] << " " <<  departure[i] << endl; 
    }

    cout << endl;

    long long int count = 0;
    long long int maxCount = 0;

    long long int i=0, j=0;
    while(i<n && j<n){
        if(arrival[i]<departure[j]){
            count++;
            i++;
        } else {
            count-=1; //Ek insaan chala gya, kyuki arrival departure se jada ho gya
            //For eg, 33 > 21, this means, 21 wle insaan ke phle phle 2 log aye,
            // fir jab teesra aya 33 pr, tb tk 21 wala laut gya, islie count-=1
            j++;
        }

        if(maxCount < count){
            maxCount = count;
        }
    }

    cout << maxCount << endl;
    return 0;
}
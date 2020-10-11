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
    //OJ;
    FIO;
    long long int n;
    cin >> n;
    long long int* st = new long long int[n];
    long long int* et = new long long int[n];
    for(long long int i=0; i<n; i++){
        cin >> st[i] >> et[i];
    }

    sort(st, st+n);
    sort(et, et+n);    

    long long int movie = 0;
    long long int start = 0, end = 0;
    int flag = 0;
    while(start < n && end < n){
        if(st[start] < et[end] && flag == 0){
            flag = 1;
            movie++;
        } else if(st[start] >= et[end]){
            flag = 0;
            end++;
        } else {
            start++;
        }
    }

    cout << movie << endl;
    return 0;
}
#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int main() 
{
    FIO;
   // OJ;
    int n;
    cin >> n;
    int* arr = new int[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    map<int, int> m;
    int ans = 0;
    for(int i=0, j=0; i<n; ++i){
        while(j<n && m[arr[j]]<1){
            m[arr[j]]++;
            ++j;
        }
        ans = max(j-i, ans);
        m[arr[i]]--;
    }
    cout << ans<< endl;
    

return 0;
   
}
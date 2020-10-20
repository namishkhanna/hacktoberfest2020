#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int main() 
{
   // OJ;
    FIO;
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i].first;
        v[i].second = i+1;
    }  

    sort(v.begin(), v.end());
    int i=0, j = n-1;
    while(i<j){
        if(v[i].first + v[j].first == x){
            cout << v[i].second << " " << v[j].second << endl;
            return 0;
        } else if(v[i].first + v[j].first < x){
            i++;
        } else {
            j--;
        }
    }

    cout << "IMPOSSIBLE" << endl;
   
}
#include <iostream>
#include<algorithm>
#include<vector>
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
    int n;
    cin >> n;
    vector<int> v;
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        int p = upper_bound(v.begin(), v.end(), a)-v.begin();
        if(p<v.size()){
            v[p] = a;
        } else {
            v.push_back(a);
        }
    }

    cout << v.size() << endl;
    
    return 0;
}
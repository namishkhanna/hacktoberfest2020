#include <iostream>
#include<vector>
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
    vector<int> v = {1, 7, 8};
    int it = lower_bound(v.begin(), v.end(), 3)-v.begin();
    cout << it << endl;
    return 0;
}
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

#define ll long long int

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
    int n, target;
    cin >> n >> target;
    vector<int> c(n);
    for (int &v : c)
        cin >> v;
    
    int mod = 1e9+7;
    vector<vector<int>> dp(n+1, vector<int>(target+1, 0));
    dp[0][0] = 1;
    for(int i=1; i<=n; i++){
        for(int j=0; j<=target; j++){
            dp[i][j] = dp[i-1][j];
            if(j-c[i-1]>=0){
                (dp[i][j]+=dp[i][j-c[i-1]])%=mod;
            }
        }
    }

    cout << dp[n][target] << endl;
    return 0;
}
#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <set>
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
    int mod = 1e9 + 7;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dp(n, vector<int>(m + 1, 0));
    int x0;
    cin >> x0;
    if (x0 == 0)
    {
        fill(dp[0].begin(), dp[0].end(), 1);
    }
    else
    {
        dp[0][x0] = 1;
    }
    for (int i = 1; i < n; i++)
    {
        int x;
        cin >> x;
        if (x == 0)
        {
            for (int j = 1; j <= m; j++)
            {
                for (int k : {j - 1, j, j + 1})
                {
                    if (k >= 1 && k <= m)
                    {
                        (dp[i][j] += dp[i - 1][k]) %= mod;
                    }
                }
            }
        }
        else
        {
            for (int k : {x - 1, x, x + 1})
            {
                if (k >= 1 && k <= m)
                {
                    (dp[i][x] += dp[i - 1][k]) %= mod;
                }
            }
        }
    }
    

    int ans = 0;
    for(int i=1; i<=m; i++){
        (ans+= dp[n-1][i])%=mod;
    }

    cout << ans << endl;
}
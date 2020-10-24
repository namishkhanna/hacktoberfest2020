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

void BottomUp(int target, vector<int> c, int n)
{
    int mod = 1e9 + 7;
    vector<int> dp(target + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= target; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i - c[j] >= 0)
            {
                (dp[i] += dp[i - c[j]]) %= mod;
            }
        }
    }
    cout << dp[target] << endl;
}

int main()
{
    //OJ;
    int n, target;
    cin >> n >> target;
    vector<int> c(n);
    for (int &v : c)
    {
        cin >> v;
    }

    BottomUp(target, c, n);

    return 0;
}
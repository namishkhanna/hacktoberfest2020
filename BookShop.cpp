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
    OJ;
    int n, maxBooks;
    cin >> n >> maxBooks;
    int* prices = new int[n];
    int* pages = new int[n];

    for(int i=0; i<n; i++){
        cin >> prices[i];
    }

    for(int i=0; i<n; i++){
        cin >> pages[i];
    }
    
    vector<vector<int>> dp(n+1, vector<int>(maxBooks+1, 0));
    for(int i=1; i<=n; i++){
        for(int j= 0; j <=maxBooks; j++){
            dp[i][j] = dp[i-1][j];
            int left = j-prices[i-1];
            if(left>=0){
                dp[i][j] = max(dp[i][j], dp[i-1][left]+pages[i-1]);
            }

        }
    }

    for(int i=0; i<=n; i++){
        for(int j=0; j<=maxBooks; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

}
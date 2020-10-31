#include <bits/stdc++.h>
typedef long long int lli;
typedef long double ldb;
 
#define endl '\n'
#define loop(i, m, n) for (lli i = m; i < n; i++)
#define loope(i, m, n) for (lli i = m; i <= n; i++)
#define epool(i, m, n) for (lli i = m; i >= n; i--)
#define pool(i,m,n) for(lli i=m; i>n; i++)
#define maxe *max_element
#define mine *min_element
#define plli pair<lli, lli>
#define mod 1000000007
#define mod2 998244353
#define vt vector<lli>
#define fi first
#define se second
#define pb push_back
#define umap unordered_map
#define mmap multimap
#define mp make_pair
#define inp1(a) cin >> a
#define inp2(a, b) cin >> a >> b
#define inp3(a, b, c) cin >> a >> b >> c
#define inp4(a, b, c, d) cin >> a >> b >> c >> d
#define inp5(a, b, c, d, e) cin >> a >> b >> c >> d >> e
#define inp6(a, b, c, d, e, f) cin >> a >> b >> c >> d >> e >> f
#define pr0() cout << " "
#define pr1(a) cout << a << " "
#define pr2(a, b) cout << a << " " << b << " "
#define pr3(a, b, c) cout << a << " " << b << " " << c << " "
#define pr4(a, b, c, d) cout << a << " " << b << " " << c << " " << d << " "
#define emp emplace //used to push a pair etc..
#define empf emplace_front
#define empb emplace_back
#define ret(x) return cout << x, 0;
#define all(v) v.begin(),v.end()
#define present(s,x) (s.find(x) != s.end())
#define cpresent(s,x) (find(all(s),x) != s.end())
#define tr(container, it) for(__typeof(container.begin()) it = container.begin(); it != container.end(); it++)
//especially for deque both sides dynamic
#define pf push_front
//list doubly linked lists can insert at mid. splice fn can be used
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
using namespace std;
 
lli gcd(lli a, lli b){
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
 
lli lcm(lli a, lli b){
    return (a * b) / gcd(a, b);
}
 
lli modi(lli n,lli m=mod){ 
    if(n==0) return 0;
    n%=m;
    n+=m;
    n%=m;
    return n;
}
 
 
lli mpow(lli base, lli exp){
    base %= mod;
    lli result = 1;
    while (exp > 0){
        if (exp & 1)
            result = ((lli)result * base) % mod;
        base = ((lli)base * base) % mod;
        exp >>= 1;
    }
    return result;
}

const lli N=2e5+5;
//lli a[N]={0},b[N]={0};

void solve(){
    lli i = 0,j = 0;
    
    lli n,m;
    cin >> n;
    lli arr[n];
    lli s=0;
    loop(i,0,n) cin >> arr[i],s+=arr[i];
    if(s%2!=0) cout << "No";
    else m=12;
    bool dp[n+1][m+1]={0};
//    dp[i][j] : can we make a sum of j from first i elements
    dp[0][0]=1;
    loop(i,1,m+1) dp[0][i]=0;
    loop(i,1,n+1){
        loop(j,0,m+1){
                if(j>=arr[i]){
                    if(dp[i-1][j]==1 || dp[i-1][j-arr[i]]==1){
                        dp[i][j]=1;
                    }
                    else dp[i][j]=0;
                }
                else dp[i][j]=dp[i-1][j];  
        }
    }
    loop(i,0,n+1){
        loop(j,0,m+1){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    if(dp[n][m]) cout << "Yes";
    else cout << "No";
    cout << endl;
}

int32_t main(){
    fast_io
    
//   freopen("input.txt","r",stdin);
//   freopen("output.txt","w",stdout);

    solve();

}

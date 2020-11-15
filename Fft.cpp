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
 
lli modi( lli n, lli m=mod ){ 
    n%=m;
    n+=m;
    n%=m;
    return n;
}
 
lli fib(lli n){ 
  double phi = (1+sqrt(5))/2; 
  return round(pow(phi,n)/sqrt(5)); 
} 
 
lli fibn(lli n){
    if (n == 0 || n == 1)
        return 1;
    else{
        lli arr[n + 1];
        arr[0] = 0;
        arr[1] = 1;
        for (lli i = 2; i <= n; i++){
            arr[i] = arr[i - 1] + arr[i - 2];
        }
        return arr[n];
    }
}
 
bool sortbysec(const pair<int,int> &a, const pair<int,int> &b){ 
    return (a.second < b.second); 
}
 
bool sortinrev(const pair<int,int> &a, const pair<int,int> &b){ 
       return (a.first > b.first); 
}
 
bool sortbysecdesc(const pair<int,int> &a,const pair<int,int> &b){ 
       return a.second>b.second; 
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
 
lli modInverse(lli n) { 
    return mpow(n, mod-2); 
}
 
lli nCr(lli n, lli r){ 
   if (r==0) 
      return 1; 
    lli fac[n+1]; 
    fac[0] = 1; 
    for (int i=1 ; i<=n; i++) 
        fac[i] = fac[i-1]*i%mod; 
    return (fac[n]* modInverse(fac[r]) % mod * 
            modInverse(fac[n-r]) % mod) % mod; 
}
 
lli is_prime(lli a){
    lli i;
    if (a == 2 || a == 3)
        return 1;
    else
        for (i = 2; i * i <= a; i++){
            if (a % i == 0)
                return 0;
        }
    return 1;
}
 
lli digsum(lli n){
    return floor(log10(n)) + 1;
}

double INF=1e100;
double EPS=1e-12; 
#define MAX 500 
  
lli multiply(lli x,lli res[],lli res_size); 
 
lli factorial(lli n) { 
    lli res[MAX]; 
    res[0] = 1; 
    lli res_size = 1; 
    for(lli x=2; x<=n; x++) 
        res_size = multiply(x, res, res_size); 
    for (lli i=res_size-1; i>=0; i--) 
        cout << res[i]; 
} 
 
lli multiply(lli x,lli res[],lli res_size) { 
    lli carry = 0;   
    for (lli i=0; i<res_size; i++) { 
        lli prod = res[i] * x + carry;   
        res[i] = prod % 10;   
        carry  = prod/10;     
    } 
    while (carry) { 
        res[res_size] = carry%10; 
        carry = carry/10; 
        res_size++; 
    } 
    return res_size; 
}
 
lli binsearch(lli arr[], lli l, lli r, lli no){
    while (l <= r){
        lli mid = (l + r) / 2;
        if (arr[mid] == no)
            return mid;
        else if (arr[mid] < no)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return -1;
}
 
string sortString(string &str){
    lli i = 0, j = 0, k = 0;
    lli charCount[26] = {0};
    loop(i, 0, str.length())
        charCount[str[i] - 'a']++;
    loop(i, 0, 26){
        loop(j, 0, charCount[i]){
            str[k++] = char('a' + i);
        }
    }
    return str;
}

using cd = complex<double>;
const double PI = acos(-1);
 
void fft(vector<cd> &a, bool invert) {
    lli n = a.size();
    if (n == 1)
        return;
 
    vector<cd> a0(n / 2), a1(n / 2);
    for (lli i = 0; 2 * i < n; i++) {
        a0[i] = a[2*i];
        a1[i] = a[2*i+1];
    }
    fft(a0, invert);
    fft(a1, invert);
 
    double ang = 2 * PI / n * (invert ? -1 : 1);
    cd w(1), wn(cos(ang), sin(ang));
    for (int i = 0; 2 * i < n; i++) {
        a[i] = a0[i] + w * a1[i];
        a[i + n/2] = a0[i] - w * a1[i];
        if (invert) {
            a[i] /= 2;
            a[i + n/2] /= 2;
        }
        w *= wn;
    }
}  

vector<lli> multpoly(vector<lli> const& a, vector<lli> const& b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    lli n = 1;
    while (n < a.size() + b.size())
        n <<= 1;
    fa.resize(n);
    fb.resize(n);
 
    fft(fa, false);
    fft(fb, false);
    for (lli i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);
 
    vector<lli> result(n);
    for (lli i = 0; i < n; i++)
        result[i] = round(fa[i].real());
    return result;
}

struct PT{
    double x,y;
    PT(){}
    PT(double x,double y) : x(x),y(y){        
    }
    PT(const PT &p):x(p.x),y(p.y){
    }
    PT operator+(const PT &p) const{
        return PT(x+p.x,y+p.y);
    }
    PT operator-(const PT &p) const{
        return PT(x-p.x,y-p.y);
    }
    PT operator*(double c) const{
        return PT(x*c,y*c);
    }
    PT operator/(double c) const{
        return PT(x/c,y/c);
    }
};

double dot(PT p,PT q){
    return p.x*q.x+p.y*q.y;
}

double dist2(PT p,PT q){
    return dot(p-q,p-q);
}

double cross(PT p,PT q){
    return p.x*q.y-p.y*q.x;
}

PT RotateCCWby90(PT p){
    return PT(-p.y,p.x);
}

PT RotateCWby90(PT p){
    return PT(p.y,-p.x);
}

PT RotateCCW(PT p,double t){
    return PT(p.x*cos(t)-p.y*sin(t),p.x*sin(t)+p.y*cos(t));
}

// Project point c onto line through a and b

PT ProjectPointonLine(PT a,Pt b,PT c){
    return a+(b-a)*dot(c-a,b-a)/dot(b-a,b-a);
}
// Project point c on line segment through a,b
PT ProjectPointSegment(PT a,PT b,PT c){
    double r=dot(b-a,b-a);
    if(fabs(r)<EPS) return a;
    r=dot(c-a,b-a)/r;
    if(r<0) return a;
    if(r>1) return b;
    return a+(b-a)*r;
}
// Distance from line segment
double DistancePointSegment(PT a,PT b,PT c){
    return sqrt(dist2(c,ProjectPointSegment(a,b,c)));
}

double DistancePointPlane(double x,double y,double z,double a,double b,double c,double d){
    return fabs(a*x+b*y+c*z-d)/sqrt(a*a+b*b+c*c);
}
// Checking if lines are parallel or collinear
bool LinesareParallel(PT a,PT b,PT c,PT d){
    return fabs(cross(b-a,c-d))<EPS;
}

bool LinesCollinear(PT a,PT b,PT c,PT d){
    return LinesareParallel(a,b,c,d)&&fabs(cross(a-b,a-c))<EPS && favs(cross(c-d,c-a))<EPS;
}
//Checking if 2 segments intersect
bool SegementsIntersect(PT a,PT b,PT c,PT d){
    if(LinesCollinear(a,b,c,d)){
        if(dist2(b,c)<EPS || dist2(b,d)<EPS)
    }
}
 
const lli N=2e5+5;
bool vis[N];
vt adj[N];
 
vt primesv(lli n){
    vt v;
    lli x=n;
    loope(i,2,sqrt(n)+1){
        if(x%i==0){
            x=x/i;
            v.pb(i);
        }
    }
    return v;
}
 
int32_t main(){
    fast_io
    lli i = 0,j = 0;
 //   freopen("input.txt","r",stdin);
 //   freopen("output.txt","w",stdout);
    
    complex<double> mycomplex(3.0,3.0);
    pr2(real(mycomplex),imag(mycomplex));
    cout << endl;
    cout << abs(mycomplex) << endl;
    cout << arg(mycomplex) << endl;
    cout << polar(mycomplex) << endl;
    //cout << 3*sin(4) << endl;
    cout << norm(mycomplex) << endl;
    complex<double> conjugate=conj(mycomplex);
    cout << conjugate*mycomplex  << endl;
}

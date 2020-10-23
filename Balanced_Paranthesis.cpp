#include <bits/stdc++.h>
using namespace std;

//    INPUT: 3
//    OUTPUT
//          ((()))
//          (()())
//          (())()
//          ()(())
//          ()()()

void solve(int o, int c, string op, vector<string> &ans)
{
    if(o == 0 && c == 0){
        ans.push_back(op);
        return;
    }
    string op1 = op + '(';
    string op2 = op + ')';
    if(o != 0)
        solve(o-1, c, op1, ans);
    
    if(c>o)
        solve(o, c-1, op2, ans);
    
    return;
}

vector<string> balancedParanthesis(int t)
{
    int open = t, close = t;
    string op = "";
    vector<string> ans;
    solve(open, close, op, ans);
    return ans;
}

int main()
{
    rex;

    int t; cin>>t;
    vector<string> paranthesis = balancedParanthesis(t);
    for(auto i: paranthesis)
        cout<<i<<endl;

    return 0;
}

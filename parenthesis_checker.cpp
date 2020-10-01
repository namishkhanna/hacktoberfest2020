#include <bits/stdc++.h>
using namespace std;

bool match(char a,char b)
{   if(a=='{' && b=='}')
        return true;
    if(a=='(' && b==')')
        return true;
    if(a=='[' && b==']')
        return true;
    return false;
}

bool balanced(string exp)
{   stack<char> st;
    int len = exp.length();
    
    for(int i=0;i<len;i++)
    {   if(exp[i]=='{' || exp[i]=='('||exp[i]=='[')
            st.push(exp[i]);
        else
        {   if(st.empty())
                return false;
            char c = st.top();
            if(match(c,exp[i]))
            {
                st.pop();
            }
            else{
                return false;
            }
        }
    }
    if(st.empty())
        return true;
    return false;
}

int main() {
	
    string str;
    cin>>str;
    if(balanced(str))
        cout<<"balanced"<<endl;
    else
        cout<<"not balanced"<<endl;
	
	return 0;
}
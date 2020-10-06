#include<iostream>
#include<cstring>
#include<stack>
using namespace std;
stack<char> st;
int prec(char c)
{
    if(c == '^')
    return 3;
    else if(c == '*' || c == '/')
    return 2;
    else if(c == '+' || c == '-')
    return 1;
    else
    return -1;
}
bool IsOperand(char C)
{
	if(C >= '0' && C <= '9') return true;
	if(C >= 'a' && C <= 'z') return true;
	if(C >= 'A' && C <= 'Z') return true;
	return false;
}
bool IsOperator(char C)
{
	if(C == '+' || C == '-' || C == '*' || C == '/' || C== '^')
		return true;

	return false;
}

string infixTopost(string exp)
{
    string res = "";


    for(int i=0;i<exp.length();i++)
    {
        if(IsOperand(exp[i]))
        {
           res+=exp[i];
        }
        else if(IsOperator(exp[i]))
		{
			while(!st.empty() && st.top() != '(' && prec(exp[i])<= prec(st.top()))
            {
                res += st.top();
                st.pop();
            }
            st.push(exp[i]);
		}
        else if(exp[i] == '(')
        {
          st.push('(');
        }
        else if(exp[i] == ')')
        {
            while(!st.empty() && st.top() != '(')
            {
                res+= st.top();
                st.pop();
            }
            if(st.top() == '(')
            {
                char c = st.top();
                st.pop();
            }
        }
    }

    while(!st.empty())
    {
        res += st.top();
        st.pop();
    }

    cout <<res<<" "<<endl;

}

int main()
{
    string infix = "(7-5)*(9/2)+2^3*(8-2)";
    infixTopost(infix);

    return 0;
}

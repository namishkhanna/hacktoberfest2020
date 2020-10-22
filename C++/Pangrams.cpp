#include<bits/stdc++.h>
using namespace std;

string panagrams(string s)
{
    int c = 0;

    transform(s.begin(), s.end(), s.begin(),::tolower);

    sort(s.begin(),s.end());

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != s[i + 1])
            c++;
    }

    if (c == 27)
        cout<<"panagram"<<endl;
    else
        cout<<"not panagram"<<endl;
    return 0;
}

int main()
{
    string s;
    s = "We promptly judged antique ivory buckles for the next prize";
    cout<<panagrams(s);
}

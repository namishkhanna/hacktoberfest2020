/*
Given a string S and text T. Output the smallest window in the string S having all characters of the text T. Both the string S and text T contains lowercase english alphabets.

Input:
First line of the input contains an integer T, denoting the number of test cases. Then T test case follows. Each test contains 2 lines having a string S and next line contains text T.

Output:
Output the smallest window of the string containing all the characters of the text. If such window doesn`t exist or this task can not be done then print -1.
*/

#include <bits/stdc++.h>
using namespace std;

void window(string s,string t)
{       
    int len = s.length();
    int tlen = t.length();
    int i;
    if(len<tlen)
    {   
        cout<<-1<<endl;
        return;
    }
    
    int test[255]={0};
    
    for(i=0;i<tlen;i++)
    {   test[t[i]]++;
        
    }   
    
    int start_ind =-1,start=0;
    int minlen = INT_MAX;
    int count=0;
    int org[255]={0};
    
    for(i=0;i<len;i++)
    {   org[s[i]]++;
        if(org[s[i]]<= test[s[i]])
            count++;
        
        if(count== tlen)
        {
            while(org[s[start]]>test[s[start]] && start<len)
            {   org[s[start]]--;
                start++;
            }
            if((i-start+1)<minlen)
            {
                start_ind = start;
                minlen = (i-start+1);
            }
        }
        
    }
    if(minlen!=INT_MAX)
    {
        string ans = s.substr(start_ind,minlen);
        cout<<ans<<endl;
    }
    else
        cout<<-1<<endl;
}

int main() {
    int t;
    cin>>t;
    while(t--)
    {   string s,t;
        cin>>s;
        cin>>t;
        
        window(s,t);
    }
	return 0;
}
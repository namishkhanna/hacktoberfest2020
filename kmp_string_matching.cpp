#include<bits/stdc++.h>
using namespace std;

int* getlps(string patt){
    int len=patt.length();
    int* lps=new int[len];

    lps[0]=0;
    int i=1;
    int j=0;

    while(i<len){
        if(patt[i]==patt[j]){
            lps[i]=j+1;
            j++;
            i++;
        }
        else{
            if(j==0){
                lps[i]=0;
                i++;
            }
            else j=lps[j-1];
        }
    }
    return lps;
}

int main(){
    string s;
    cin >> s;
    
    int* ans=new int[s.size()];
    ans=getlps(s);
    
    for(int i=0;i<s.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;

}

#include<bits/stdc++.h>
using namespace std; 

int main() 
{ 
	string str ;
	getline(cin,str);                                 //read the string
    for(int i=0;i<str.length();i++) 
	{ 
		if(isupper(str[i]))
		{ 
			if (i!= 0)                              //Next line before the next capital letter
			cout << endl; 
        
        	cout << str[i]; 
		} 
		else
			cout << str[i];                        //print lowercse characters
	} 
	return 0; 
} 


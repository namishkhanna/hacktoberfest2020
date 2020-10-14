//Recursive function to print the reverse of a given string
#include <bits/stdc++.h>
using namespace std;

void reverse_string(string line);

int main()
{
    cout<<"Enter the string to be reversed \n";
    string a;
    getline (cin, a);
    reverse_string(a);
    return 0;
}
void reverse_string(string line)
{
    if(line.size() == 0)
    {
        return;
    }
    reverse_string(line.substr(1));
    cout << line[0];
}


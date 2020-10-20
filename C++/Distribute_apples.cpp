/*

Problem statement: 

Kitahara Haruki has bought n apples for Touma Kazusa and Ogiso Setsuna. 
Now he wants to divide all the apples between the friends.

Each apple weights 100 grams or 200 grams. Of course Kitahara Haruki doesn't want to offend any of his friend. 
Therefore the total weight of the apples given to Touma Kazusa must be equal to the total weight of the apples given to Ogiso Setsuna.

But unfortunately Kitahara Haruki doesn't have a knife right now, so he cannot split any apple into some parts. 
Please, tell him: is it possible to divide all the apples in a fair way between his friends?
*/

/* Solution: */

/*
Reference: https://codeforces.com/problemset/problem/433/A
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a = 0, b = 0, val;
    for(int i = 0; i < n; i++) {
        cin >> val;
        if(val == 100)
            a++;
        else b++;
    }

    if(a&1) {
        cout << "NO" << endl;
    } else {
        if(a==0 && (b&1)) {
            cout << "NO" << endl;
            return 0;
        }

        if(b%2 == 0 || (b > a)) {
            cout << "YES" << endl;
            return 0;
        }

        int half = (a*100 + b*200)/2;
        for(int i = 0; i <= b; i++) {
            if((i*200 <= half && (half-i*200 <= a*100)))
            {
                cout << "YES" << endl;
                return 0;
            }
        }

        cout << "NO" << endl;
    }
    return 0;
}
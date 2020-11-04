#include <bits/stdc++.h>
using namespace std;

//      OUTPUT
//            Equivalent Balanced Ternary of 238 is: 100Z11

string balancedTernary(int n)
{
	string output = "";
	while (n > 0) {
		int rem = n % 3;
		n = n / 3;
		if (rem == 2) {
			rem = -1;
			n++;
		}
		output = (rem == 0
					? '0'
					: (rem == 1)
							? '1'
							: 'Z')
				+ output;
	}
	return output;
}

int main()
{

	int n = 238;

	cout << "Equivalent Balanced Ternary of "
		<< n << " is: "
		<< balancedTernary(n);

	return 0;
}

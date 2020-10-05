// C++ code of two sum problem based on two pointer algorithm
#include<bits/stdc++.h>
#define ops(z) cout<<z<<" "
#define op(z) cout<<z<<endl
using namespace std;

void two_pointer(vector<int> a, int key)
{
	int ans = 0, l = 0, r = a.size() - 1;
	while (ans != key)
	{
		ans = a[l] + a[r];
		if (ans == key)break;
		if (ans > key)
		{
			r--;
		}
		else
			l++;
	}
	ops(l); op(r);
}
int main()
{
	int n, k, i;
	cin >> n >> k;
	vector<int>a;
	for (i = 0; i < n; i++)
	{
		int g;
		cin >> g;
		a.push_back(g);
	}
	two_pointer(a, k);
}

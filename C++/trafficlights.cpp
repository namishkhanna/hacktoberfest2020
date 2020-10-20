#include <iostream>
#include<algorithm>
#include<set>

using namespace std;

#define OJ                            \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

int main()
{
    OJ;
   	int x, n, point, left, right;
	cin >> x >> n;
	set<int> points = {0, x};
	multiset<int> lengths = {x};
	while (n--)
	{
		cin >> point;
		// find the position to insert the current point
		auto it = points.upper_bound(point);

		// [left, right] : the range in which the point is being inserted
		left = *prev(it);
		right = *it;

		// remove that range from lengths
		lengths.erase(lengths.find(right - left));
		// add new lengths
		lengths.insert(point - left);
		lengths.insert(right - point);

		// insert the new point
		points.insert(it, point);

		// output the largest length
		cout << *lengths.rbegin() << " ";
	}
	return 0;
}
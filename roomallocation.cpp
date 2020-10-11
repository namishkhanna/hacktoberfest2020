#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;


#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);


int main()
{
    OJ;

	int n, x, y;
	cin >> n;
	vector<pair<int, pair<int, int>>> v;
	for (int i = 1; i <= n; i++)
	{
		cin >> x >> y;
		v.push_back({x, {-1, i}}); // comes in
		v.push_back({y, {1, i}});  // goes out
	}
	sort(v.begin(), v.end());

    for(int i=1; i<=n; i++){
        cout << v[i].first << " " << v[i].second.first << " " << v[i].second.second << endl;
    }

	vector<int> rooms;
	int occupied = 0, max_rooms = 0, in_or_out, ind;
	int ans[200005];
	for (auto ele : v)
	{
		in_or_out = ele.second.first;
		ind = ele.second.second;

		if (in_or_out == 1)
		{
			rooms.push_back(ans[ind]);
		}
		else if (occupied == rooms.size())
		{
			ans[ind] = ++max_rooms;
		}
		else
		{
			ans[ind] = rooms[occupied++];
		}
	}
	cout << max_rooms << endl;
	for (int i = 1; i <= n; i++)
	{
		cout << ans[i] << " ";
	}
	return 0;
}
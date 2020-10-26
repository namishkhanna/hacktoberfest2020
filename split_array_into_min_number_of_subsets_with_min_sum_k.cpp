#include <bits/stdc++.h>
using namespace std;

int cntMinSub(int arr[],
			int N, int K)
{
	int res = 0;
	int start = 0;
	int end = N - 1;

	sort(arr, arr + N);
	while (end - start > 1) {
		if (arr[start] + arr[end]
			<= K) {
			start++;
		}
		else {
			res++;
			end--;
		}
	}


	if (end - start == 1) {
		if (arr[start] + arr[end]
			<= K) {
			res++;
			start++;
			end--;
		}
		else {
			res++;
			end--;
		}
	}
	if (start == end) {
		res++;
	}

	return res;
}

// Driver Code
int main()
{
	int arr[] = { 2, 6, 8, 10, 20, 25 };
	int N = sizeof(arr) / sizeof(arr[0]);
	int K = 26;
	cout << cntMinSub(arr, N, K);
}

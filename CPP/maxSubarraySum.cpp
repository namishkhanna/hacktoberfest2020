// max_subarray_sum-O(N)
#include <bits/stdc++.h>
using namespace std;

int maxSumSubarray(vector<int> A)
{
    int n = A.size();
    bool f = true;
    int result = INT_MIN;
    for (auto x : A)
    {
        if (x > 0)
            f = false;
        if (x > result)
            result = x;
    }
    if (f)
        return result;
    int cs = 0;
    int ms = 0;
    for (int i = 0; i < n; i++)
    {
        cs = cs + A[i];
        if (cs < 0)
        {
            cs = 0;
        }
        ms = max(ms, cs);
    }
    return ms;
}

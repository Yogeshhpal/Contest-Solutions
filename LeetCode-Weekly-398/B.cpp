#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<bool> isArraySpecial(vector<int> &arr, vector<vector<int>> &queries)
    {
        int n = arr.size();

        if (n == 1)
        {
            return vector<bool>(queries.size(), true);
        }

        vector<int> parity(n);
        for (int i = 1; i < n; ++i)
        {
            parity[i] = (arr[i] % 2) != (arr[i - 1] % 2);
        }

        vector<int> prefix(n);
        prefix[0] = 0;
        for (int i = 1; i < n; ++i)
        {
            prefix[i] = prefix[i - 1] + parity[i];
        }

        vector<bool> ans(queries.size());
        for (int i = 0; i < queries.size(); ++i)
        {
            int l = queries[i][0];
            int r = queries[i][1];

            if (l == r)
            {
                ans[i] = true;
            }
            else
            {
                int parity_changes = prefix[r] - prefix[l];
                ans[i] = (parity_changes == (r - l));
            }
        }

        return ans;
    }
};
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isArraySpecial(vector<int> &arr)
    {
        int n = arr.size();
        for (int i = 1; i < n; i++)
        {
            if (arr[i] % 2 == 0)
            {
                if (arr[i - 1] % 2 == 0)
                    return false;
            }
            else if (arr[i] % 2 != 0)
            {
                if (arr[i - 1] % 2 != 0)
                    return false;
            }
        }
        return true;
    }
};

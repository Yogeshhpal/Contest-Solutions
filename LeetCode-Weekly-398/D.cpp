#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    unordered_map<int, unordered_map<int, unordered_map<int, int>>> memo; 

    int f1(int start, bool used, int jump, int k) {
        if (memo.count(start) && memo[start].count(used) && memo[start][used].count(jump)) {
            return memo[start][used][jump];
        }

        if (start > k + 1 || jump > 31) return 0;
        int ways = (start == k);

        if (used) {
            ways += f1(start - 1, false, jump, k);
        }
        if (start + (1 << jump) <= k + 1) {
            ways += f1(start + (1 << jump), true, jump + 1, k);
        }

        memo[start][used][jump] = ways;
        return ways;
    }

    int waysToReachStair(int k) {
        return f1(1, true, 0, k);
    }
};
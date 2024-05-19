#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
long long sumDigitDifferences(vector<int>& nums) {
         int n = nums.size();
    if (n < 2) return 0;

    int num_digits = to_string(nums[0]).size();
    long long total_difference = 0;

    vector<vector<int>> digit_count(num_digits, vector<int>(10, 0));

    for (int num : nums) {
        string num_str = to_string(num);
        for (int i = 0; i < num_digits; ++i) {
            digit_count[i][num_str[i] - '0']++;
        }
    }

    for (int i = 0; i < num_digits; ++i) {
        for (int d = 0; d < 10; ++d) {
            for (int e = d + 1; e < 10; ++e) {
                total_difference += static_cast<long long>(digit_count[i][d]) * digit_count[i][e];
            }
        }
    }

    return total_difference;
    }
};
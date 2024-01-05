/* 5th January, 2024
 * Problem: Longest Increasing Subsequence( https://leetcode.com/problems/longest-increasing-subsequence )
 * Difficulty: Medium
 * Solution: Standard
*/

#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:
        int lengthOfLIS(vector<int> &nums){
            int n = nums.size();
            vector<int> dp(n, 1);

            for (int i = 1; i < n; i++){
                for (int j = 0; j < i; j++) if (nums[j] < nums[i]) dp[i] = max(dp[j] + 1, dp[i]);
            }

            return *max_element(dp.begin(), dp.end());
        }
}

int main(){
    exit(EXIT_SUCCESS);
}

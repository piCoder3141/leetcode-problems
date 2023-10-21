/* 21st October, 2023
 * Problem: Constrained Subsequence Sum ( https://leetcode.com/problems/constrained-subsequence-sum )
 * Difficulty: Hard
 * Solution: Monotonic Deque.
*/

#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:
        int constrainedSubsetSum(vector<int> &nums, int k){
            int n = nums.size();
            vector<int> dp = nums;
            deque<int> q;
            int ans = INT_MIN;
            
            for (int i = 0; i < n; i++){
                if (!q.empty()) dp[i] = max(dp[i], nums[i] + dp[q.front()]);
                while((!q.empty()) && (i - q.front() >= k)) q.pop_front();
                while ((!q.empty()) && (dp[i] > dp[q.back()])) q.pop_back();
                q.push_back(i);
                ans = max(ans, dp[i]);
            }

            return ans;
        }
};

int main(){
    Solution solver;
    vector<int> nums{10, 2, -10, 5, 20};
    cout << solver.constrainedSubsetSum(nums, 2) << '\n';
    exit(EXIT_SUCCESS);
}

/* 8th October, 2023
 * Problem: Max Dot Product of Two Subsequences ( https://leetcode.com/problems/max-dot-product-of-two-subsequences/ )
 * Difficulty: Hard
 * Solution: Similar to LCS problem.
*/

#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:
        const int NINF = INT_MIN / 2;
        int maxDotProduct(vector<int> &a, vector<int> &b){
            int n = a.size(), m = b.size();
            vector<vector<int>> dp(n+1, vector<int>(m+1, NINF));
            dp[0][0] = 0;

            for (int i = 1; i <= n; i++){
                for (int j = 1; j <= m; j++){
                    int x = a[i-1], y = b[j-1];
                    dp[i][j] = max({ x*y, x*y + dp[i-1][j-1], dp[i][j-1], dp[i-1][j] });
                }
            }

            return dp[n][m];
        }
};

int main(){
    Solution solver;
    vector<int> nums1{2, 1, -2, 5};
    vector<int> nums2{3, 0, -6};
    cout << solver.maxDotProduct(nums1, nums2) << "\n";
    exit(EXIT_SUCCESS);
}

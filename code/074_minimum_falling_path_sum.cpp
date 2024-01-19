/* 19th January, 2024
 * Problem: Minimum Falling Path Sum ( https://leetcode.com/problems/minimum-falling-path-sum )
 * Difficulty: Medium
 * Solution: Standard DP.
*/

#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:
        int minFallingPathSum(vector<vector<int>> &matrix){
            int n = matrix.size(), m = matrix[0].size();
            vector<vector<int>> dp(2, vector<int>(m, 0));
            
            for (int j = 0; j < m; j++) dp[0][j] = matrix[0][j];
            for (int i = 1; i < n; i++){
                for (int j = 0; j < m; j++){
                    int idx = i & 1;
                    dp[idx][j] = dp[idx ^ 1][j];
                    if (j > 0) dp[idx][j] = min(dp[idx ^ 1][j-1], dp[idx][j]);
                    if (j < n-1) dp[idx][j] = min(dp[idx ^ 1][j+1], dp[idx][j]);
                    dp[idx][j] += matrix[i][j];
                }
            }

            return *min_element(dp[(n-1) & 1].begin(), dp[(n-1) & 1].end());
        }
};

int main(){
    exit(EXIT_SUCCESS);
}

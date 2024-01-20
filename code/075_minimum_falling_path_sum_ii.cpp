/* 19th January, 2024
 * Problem: Minimum Falling Path Sum II ( https://leetcode.com/problems/minimum-falling-path-sum-ii )
 * Difficulty: Hard
 * Solution: For every row, maintain the index of the minimum and the second minimum value in the dp array. While
 *           computing dp[i][j], use the minimum of the previous row, if j is not the minimum index. Otherise, use the
 *           second minimum.
*/

#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:
        pair<int, int> getMins(vector<int> &row){
            int n = row.size();
            int mn = INT_MAX, smn = INT_MAX;
            int mn_id = -1, smn_id = -1;

            for (int i = 0; i < n; i++){
                if (row[i] < mn){
                    smn = mn; smn_id = mn_id;
                    mn = row[i]; mn_id = i;
                }
                else if (row[i] < smn){
                    smn = row[i]; smn_id = i;
                }
            }

            return make_pair(mn_id, smn_id);
        }

        int minFallingPathSum(vector<vector<int>> &grid){
            int n = grid.size();
            if (n == 1) return grid[0][0];
            vector<vector<int>> dp(2, vector<int>(n));

            dp[0] = grid[0];
            pair<int, int> mins = getMins(dp[0]);

            for (int i = 1; i < n; i++){
                int idx = i & 1;
                for (int j = 0; j < n; j++){
                    if (j == mins.first){
                        dp[idx][j] = dp[idx ^ 1][mins.second] + grid[i][j];
                    }
                    else{
                        dp[idx][j] = dp[idx ^ 1][mins.first] + grid[i][j];
                    }
                }

                mins = getMins(dp[idx]);
            }

            return *min_element(dp[(n-1) & 1].begin(), dp[(n-1) & 1].end());
        }
};

int main(){
    exit(EXIT_SUCCESS);
}

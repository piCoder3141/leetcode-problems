/* 11th February, 2024
 * Problem: Cherry Pickup II ( https://leetcode.com/problems/cherry-pickup-ii )
 * Difficulty: Hard
 * Solution: Backtracking with memoization
*/

#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:
        int n, m;

        int solve(int row, int col1, int col2, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp){
            if (row >= n-1) return 0;
            if (dp[row][col1][col2] != -1) return dp[row][col1][col2];

            int ans = 0;
            for (int i = -1; i <= 1; i++){
                int ncol1 = col1 + i;
                if ((ncol1 < 0) || (ncol1 >= m)) continue;
                for (int j = -1; j <= 1; j++){
                    int ncol2 = col2 + j;
                    if ((ncol2 < 0) || (ncol2 >= m)) continue;
                    int curr = grid[row+1][ncol1] + grid[row+1][ncol2];
                    if (ncol1 == ncol2) curr -= grid[row+1][ncol1];
                    ans = max(ans, curr + solve(row+1, ncol1, ncol2, grid, dp));
                }
            }

            return dp[row][col1][col2] = ans;
        }

        int cherryPickup(vector<vector<int>> &grid){
            n = grid.size(); m = grid[0].size();
            vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));

            return grid[0][0] + grid[0][m-1] + solve(0, 0, m-1, grid, dp);
        }
};

int main(){
    exit(EXIT_SUCCESS);
}

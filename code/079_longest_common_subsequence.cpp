/* 26th January, 2024
 * Problem: Out of Bounday Paths ( https://leetcode.com/problems/out-of-boundary-paths )
 * Difficulty: Medium
 * Solution: Standard DP.
*/

#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:
        int findPaths(int m, int n, int maxMove, int startRow, int startColumn){
            const int MOD = 1e9 + 7;
            vector<vector<vector<int>>> dp(2, vector<vector<int>>(m+2, vector<int>(n+2)));
            for (int k = 0; k < 2; k++){
                for (int i = 0; i <= m; i++) dp[k][i][0] = dp[k][i][n+1] = 1;
                for (int j = 0; j <= n; j++) dp[k][0][j] = dp[k][m+1][j] = 1;
            }

            for (int mv = 1; mv <= maxMove; mv++){
                int mvid = mv & 1;
                for (int i = 1; i <= m; i++){
                    for (int j = 1; j <= n; j++){
                        dp[mvid][i][j] = ((1ll * dp[mvid^1][i-1][j]) + dp[mvid^1][i+1][j] + dp[mvid^1][i][j-1] + dp[mvid^1][i][j+1]) % MOD;
                    }
                }
            }

            return dp[maxMove & 1][startRow+1][startColumn+1];
        }
};

int main(){
    exit(EXIT_SUCCESS);
}

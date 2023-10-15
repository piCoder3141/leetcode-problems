/* 15th October, 2023
 * Problem: Number of Ways to Stay in the Same Place After Some Steps ( https://leetcode.com/problems/number-of-ways-to-stay-in-the-same-place-after-some-steps/submissions )
 * Difficulty: Hard
 * Solution: Notice that if n > steps/2, then it does not matter how large `n` is. Therefore, we can choose
 *           n = min(n, steps/2+1). From here, it's a standard dynamic programming question - 
 *           dp[steps][pos] = dp[steps-1][pos] + dp[steps-1][pos-1] + dp[steps-1][pos+1]
 *           where `steps` refers to the number of steps left, and `pos` refers to the current position in array. 
*/

#include<bits/stdc++.h>

using namespace std;


class Solution{
    public:
        int numWays(int steps, int n){
            if (n == 1) return 1;
            n = min(n, steps/2 + 1);
            const int MOD = 1e9 + 7;
            vector<vector<int>> dp(2, vector<int>(n, 0));
            dp[0][0] = 1;

            for (int s = 1; s <= steps; s++){
                int idx = s & 1;
                dp[idx][0] = (dp[idx^1][0] + dp[idx^1][1]) % MOD;
                dp[idx][n-1] = (dp[idx^1][n-1] + dp[idx^1][n-2]) % MOD;
                for (int i = 1; i < n-1; i++){
                    dp[idx][i] = (((dp[idx^1][i] + dp[idx^1][i-1]) % MOD) + dp[idx^1][i+1]) % MOD;
                }
            }

            return dp[steps&1][0];
        }
};

int main(){
    Solution solver;
    cout << solver.numWays(3, 2) << '\n';
    exit(EXIT_SUCCESS);
}

/* 28th October, 2023
 * Problem: Count Vowels Permutation ( https://leetcode.com/problems/count-vowels-permutation ) 
 * Difficulty: Hard
 * Solution: Dynamic Programming
*/

#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:
        int countVowelPermutation(int n){
            const int MOD = 1e9 + 7;
            int dp[2][5] = {0};
            for (int i = 0; i < 5; i++) dp[1][i] = 1;

            for (int i = 2; i <= n; i++){
                int x = i&1;
                int y = x ^ 1;

                dp[x][0] = dp[y][1];
                dp[x][1] = (dp[y][0] + dp[y][2]) % MOD;
                dp[x][2] = (((dp[y][0] + dp[y][1])%MOD) + ((dp[y][3] + dp[y][4]) % MOD)) % MOD;
                dp[x][3] = (dp[y][2] + dp[y][4]) % MOD;
                dp[x][4] = dp[y][0];
            }

            int ans = 0;
            for (int i = 0; i < 5; i ++) ans = (ans + dp[n&1][i]) % MOD;
            return ans;
        }
};

int main(){
    Solution solver;
    cout << solver.countVowelPermutation(5) << '\n';
    exit(EXIT_SUCCESS);
}

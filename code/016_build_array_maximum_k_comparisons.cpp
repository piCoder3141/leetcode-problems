/* 7th October, 2023
 * Problem: Build Array Where You can Find the Maximum Exactly K Comparisons ( https://leetcode.com/problems/build-array-where-you-can-find-the-maximum-exactly-k-comparisons ) 
 * Difficulty: Hard
 * Solution: DP with prefix.
*/

#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:
        const int MOD = 1e9 + 7;
        int dp[51][51][101];
        int pref_dp[51][51][101];

        int pow(int x, int y){
            long long ans = 1;
            while(y){
                if (y&1) ans = (ans * x) % MOD;
                x = (int) ((1ll * x * x) % MOD);
                y >>= 1;
            }

            return (int) ans % MOD;
        }

        int numOfArrays(int N, int M, int K){
            memset(dp, 0, sizeof(dp));
            memset(pref_dp, 0, sizeof(pref_dp));

            for (int n = 1; n <= N; n++){
                for (int m = 1; m <= M; m++){
                    dp[1][n][m] = pow(m, n-1);
                    pref_dp[1][n][m] = (pref_dp[1][n][m-1] + dp[1][n][m]) % MOD;
                }
            }

            for (int k = 2; k <= K; k++){
                for (int n = 1; n <= N; n++){
                    for (int m = 1; m <= M; m++){
                        for (int i = k-1; i < n; i++){
                            int diff = (pref_dp[k-1][i][m-1] - pref_dp[k-1][i][k-2] + MOD) % MOD;
                            int m_pow_left = pow(m, n - (i+1));
                            dp[k][n][m] = (dp[k][n][m] + ((1ll * diff * m_pow_left) % MOD)) % MOD;
                        }
                        pref_dp[k][n][m] = (pref_dp[k][n][m-1] + dp[k][n][m]) % MOD;
                    }
                }
            }

            int ans = 0;
            for (int m = K; m <= M; m++){
                ans = (ans + dp[K][N][m]) % MOD;
            }
            
            return ans;
        }
};

int main(){
    Solution solver;
    cout << solver.numOfArrays(50, 100, 50) << "\n";
    exit(EXIT_SUCCESS);
}

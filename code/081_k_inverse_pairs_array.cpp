/* 28th January, 2024
 * Problem: K Inverse Pairs Array ( https://leetcode.com/problems/k-inverse-pairs-array)
 * Difficulty: Hard
 * Solution: 
*/

#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:
        int kInversePairs(int n, int k){
            const int MOD = 1e9 + 7;
            vector<int> dp(1005); dp[0] = 1;
            vector<int> pref_dp(1005, 1); pref_dp[0] = 0;

            int nC2i = 0;
            for (int i = 2; i <= n; i++){
                nC2i += i-1;
                for (int k = min(1000, nC2i); k > 0; k--){
                    dp[k] = (pref_dp[k+1] - pref_dp[max(0, k-i+1)] + MOD) % MOD;
                }
                for(int k = 0; k < 1003; k++){
                    pref_dp[k+1] = (pref_dp[k] + dp[k]) % MOD;
                }
            }

            return dp[k];
        }
};

int main(){
    exit(EXIT_SUCCESS);
}

/* 25th January, 2024
 * Problem: Longest Common Subsequence ( https://leetcode.com/problems/longest-common-subsequence )
 * Difficulty: Medium
 * Solution: Standard DP.
*/

#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:
        int longestCommonSubsequence(string s1, string s2){
            int n = s1.length(), m = s2.length();
            vector<vector<int>> dp(2, vector<int>(m+1));

            for (int i = 1; i <= n; i++){
                for (int j = 1; j <= m; j++){
                    int id = i&1;
                    dp[id][j] = max(dp[id^1][j], dp[id][j-1]);
                    if (s1[i-1] == s2[j-1]) dp[id][j] = max(dp[id][j], 1 + dp[id^1][j-1]);
                }
            }

            return dp[n&1][m];
        }
};

int main(){
    exit(EXIT_SUCCESS);
}

/* 10th February, 2024
 * Problem: Palindromic Substrings ( https://leetcode.com/problems/palindromic-substrings )
 * Difficulty: Medium
 * Solution: Standard DP.
*/

#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:
        int countSubstrings(string s){
            int n = s.length();
            vector<vector<bool>> dp(n, vector<bool>(n));
            for (int i = 0; i < n-1; i++){
                dp[i][i] = true;
                dp[i][i+1] = (s[i] == s[i+1]);
            }
            dp[n-1][n-1] = true;

            for (int i = 0; i < n; i++){
                for (int j = i-2; j >= 0; j--) dp[j][i] = (s[i] == s[j]) && dp[j+1][i-1];
            }

            int ans = n;
            for (int i = 0; i < n; i++){
                for (int j = i+1; j < n; j++) ans += dp[i][j];
            }

            return ans;
        }
};

int main(){
    exit(EXIT_SUCCESS);
}

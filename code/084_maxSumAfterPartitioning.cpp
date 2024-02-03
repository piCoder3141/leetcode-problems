/* 3rd February, 2024
 * Problem: Partition Array for Maximum Sum ( https://leetcode.com/problems/partition-array-for-maximum-sum )
 * Difficulty: Medium
 * Solution: Use dp[i] to store the maximum sum up till index i.
*/

#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:
        int maxSumAfterPartitioning(vector<int> &a, int k){
            int n = a.size();
            vector<int> dp(n+1);
            for (int i = 0; i < n; i++){
                int mx = 0;
                for (int j = 0; j < min(k, i+1); j++){
                    mx = max(mx, a[i-j]);
                    dp[i+1] = max(dp[i+1], dp[i-j] + (mx * (j+1)));
                }
            }

            return dp[n];
        }
};

int main(){
    exit(EXIT_SUCCESS);
}

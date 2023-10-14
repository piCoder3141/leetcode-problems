/* 14th October, 2023
 * Problem: Painting the Walls ( https://leetcode.com/problems/painting-the-walls )
 * Difficulty: Hard
 * Solution: Variation of the Subset Sum problem. Notice that if we choose a wall with time `t`, we can paint `t+1`
 *           walls. So we need to find {w_i} such that sum(t_{w_i} + 1) >= n and the cost is minimum.
*/

#include<bits/stdc++.h>

using namespace std;


class Solution{
    public:
        int paintWalls(vector<int> &cost, vector<int> &time){
            int n = cost.size();
            for (int &d: time) d += 1;
            const int INF = 1e9 + 5;

            int dp[n+1];
            dp[0] = 0;
            for (int i = 1; i <= n; i++) dp[i] = INF;

            for (int i = 0; i < n; i++){
                for (int j = n; j > 0; j--){
                    dp[j] = min(dp[j], cost[i] + dp[max(j - time[i], 0)]);
                }
            }

            return dp[n];
        }
};

int main(){
    Solution solver;
    vector<int> cost{10, 15, 20};
    cout << solver.minCostClimbingStairs(cost) << '\n';
    exit(EXIT_SUCCESS);
}

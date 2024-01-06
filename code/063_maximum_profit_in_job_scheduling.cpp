/* 6th January, 2024
 * Problem: Maximum Profit in Job Scheduling ( https://leetcode.com/problems/maximum-profit-in-job-scheduling )
 * Difficulty: Hard
 * Solution: 
*/

#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:
        int jobScheduling(vector<int> &start, vector<int> &end, vector<int> &profit){
            int n = start.size(), ans = 0;
            vector<int> order(n);
            iota(order.begin(), order.end(), 0);

            sort(order.begin(), order.end(), [&](int a, int b){
                    return end[a] < end[b];
                    });

            map<int, int> dp;
            dp[0] = 0;

            for (int i = 0; i < n; i++){
                int st = start[order[i]], en = end[order[i]], prof = profit[order[i]];
                int prev = (--dp.lower_bound(st+1))->second;

                if (dp.find(en) == dp.end()){
                    dp[en] = (i > 0) ? dp[end[order[i-1]]] : 0;
                }

                dp[en] = max(dp[en], prev + prof);
                ans = max(ans, dp[en]);
            }

            return ans;
        }
};

int main(){
    exit(EXIT_SUCCESS);
}

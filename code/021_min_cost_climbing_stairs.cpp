/* 13th October, 2023
 * Problem: Min Cost Climbing Stairs ( https://leetcode.com/problems/min-cost-climbing-stairs )
 * Difficulty: Easy
 * Solution: Dynamic Programming.
*/

#include<bits/stdc++.h>

using namespace std;


class Solution{
    public:
        int minCostClimbingStairs(vector<int> &cost){
            int a=0, b=0, c;
            for (int i = 2; i <= cost.size(); i++){
                c = min(cost[i-2] + a, cost[i-1] + b);
                a = b; b = c;
            }

            return c;
        }
};

int main(){
    Solution solver;
    vector<int> cost{10, 15, 20};
    cout << solver.minCostClimbingStairs(cost) << '\n';
    exit(EXIT_SUCCESS);
}

/* 21st January, 2024
 * Problem: House Robber ( https://leetcode.com/problems/house-robber )
 * Difficulty: Medium
 * Solution: Standard DP. Either you rob the ith house or you don't.
*/

#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:
        int rob(vector<int> &nums){
            int a = nums[0], b = 0, n = nums.size();
            for (int i = 0; i < n; i++){
                int tmp = max(a, b + nums[i]);
                b = a; a = tmp;
            }

            return a;
        }
};

int main(){
    exit(EXIT_SUCCESS);
}

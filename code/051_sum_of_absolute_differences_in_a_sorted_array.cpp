/* 25th November, 2023.
 * Problem: Sum of Absolute Differences in a Sorted Array () 
 * Difficulty: Medium
 * Solution: Iteratively compute sum of greater and smaller array.
*/

#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:
        vector<int> getSumAbsoluteDifferences(vector<int>& nums){
            int n = nums.size();
            vector<int> ans(n);
            int big_sum = accumulate(nums.begin(), nums.end(), 0), small_sum = 0;

            for (int i = 0; i < n; i++){
                ans[i] = big_sum - ((n-i) * nums[i]) + ((i * nums[i]) - small_sum);
                big_sum -= nums[i];
                small_sum += nums[i];
            }

            return ans;
        }
};

int main(){
    exit(EXIT_SUCCESS);
}

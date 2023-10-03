/* 3rd October, 2023
 * Problem: Number of Good Pairs ( https://leetcode.com/problems/number-of-good-pairs ) 
 * Difficulty: Easy
 * Solution: Iterate over all pairs and count equal pairs.
*/

#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:
        int numIdenticalPairs(vector<int>& nums){
            int n = nums.size();
            int ans = 0;
            for (int i = 0; i < n-1; i++){
                for (int j = i+1; j < n; j++){
                    ans += (nums[i] == nums[j]);
                }
            }

            return ans;
        }
};

int main(){
    Solution solver;
    vector<int> nums{1, 2, 1, 3, 4, 2};
    cout << solver.numIdenticalPairs(nums) << "\n";
    exit(EXIT_SUCCESS);
}

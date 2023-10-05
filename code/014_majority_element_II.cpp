/* 5th October, 2023
 * Problem: Majority Element II ( https://leetcode.com/problems/majority-element-ii ) 
 * Difficulty: Medium
 * Solution: Sort and check count of each run.
*/

#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:
        vector<int> majorityElement(vector<int>& nums){
            vector<int> ans;
            int n = nums.size();
            int cutoff = n/3;
            sort(nums.begin(), nums.end());
            int run = 1;
            for (int i = 1; i < n; i++){
                if (nums[i] == nums[i-1]){
                    run++;
                }
                else{
                    if (run > cutoff) ans.push_back(nums[i-1]);
                    run = 1;
                }
            }
            if (run > cutoff) ans.push_back(nums[n-1]);
            return ans;
        }
};

int main(){
    Solution solver;
    vector<int> nums{1, 2, 1, 3, 4, 2};
    cout << solver.majorityElement(nums) << "\n";
    exit(EXIT_SUCCESS);
}

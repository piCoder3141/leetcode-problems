/* 10th October, 2023
 * Problem: Minimum Number of Operations to Make Array Continuous ( https://leetcode.com/problems/minimum-number-of-operations-to-make-array-continuous )
 * Difficulty: Hard
 * Solution: Sort the elements and only keep the unique numbers. We can find a 'best' continous sequence that has its
 *           starting point at one of the elements in the array. Iterate over each element assuming it is the starting
 *           point and return the minimum possible answer.
*/

#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:
        int minOperations(vector<int> &nums){
            sort(nums.begin(), nums.end());
            int n = nums.size();

            vector<int>::iterator ip = unique(nums.begin(), nums.end());
            nums.resize(distance(nums.begin(), ip));
            int m = nums.size();

            int ans = n-1;
            for (int i = 0; i < m-1; i++){
                int d = nums[i];
                int nxt = upper_bound(nums.begin(), nums.end(), d+n-1) - nums.begin() - 1;
                ans = min(ans, n - (nxt - i + 1));
            }

            return ans;
        }
};

int main(){
    Solution solver;
    vector<int> nums{1, 2, 3, 5, 6};
    cout << solver.minOperations(nums) << "\n";
    exit(EXIT_SUCCESS);
}

/* 29th September, 2023
 * Problem: Monotonic Array ( https://leetcode.com/problems/monotonic-array )
 * Difficulty: Easy
 * Solution: There are only two possibilities (increasing or decreasing), check both.
*/

#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:
        bool isMonotonic(vector<int> &nums){
            if (nums.size() <= 2) return true;
            bool inc = true, dec = true;
            for (int i = 1; i < nums.size(); i++){
                if (nums[i] > nums[i-1]) dec = false;
                if (nums[i] < nums[i-1]) inc = false;
            }

            return (inc || dec);
        }
};

int main(){
    Solution solver;
    vector<int> nums{1, 2, 4, 6, 5, 3};
    cout << solver.isMonotonic(nums) << "\n";
    exit(EXIT_SUCCESS);
}

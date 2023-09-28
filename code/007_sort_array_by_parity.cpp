/* 28th September, 2023
 * Problem: Sort Array By Parity ( https://leetcode.com/problems/sort-array-by-parity )
 * Difficulty: Easy
 * Solution: Create custom sort function.
*/

#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:
        vector<int> sortArrayByParity(vector<int> &nums){
            sort(nums.begin(), nums.end(), [](int x, int y){
                    if ((x + y) & 1){
                        if (x & 1) return false;
                        else return true;
                    }
                    else{
                        return x < y;
                    }
                    });
            return nums;
        }
};

int main(){
    Solution solver;
    vector<int> nums{1, 2, 4, 6, 5, 3};
    vector<int> ans = solver.sortArrayByParity(nums);
    for (int i = 0; i < ans.size(); i++) cout << nums[i] << " \n"[i == ans.size() -1];
    // cout << solver.sortArrayByParity(nums) << "\n";
    exit(EXIT_SUCCESS);
}

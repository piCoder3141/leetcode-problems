/* 2nd January, 2024
 * Problem: Convert An Array Into a 2D Array With Conditions ( https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions )
 * Difficulty: Medium
 * Solution: Sort the array and place the same elements in a different row.
*/

#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:
        vector<vector<int>> findMatrix(vector<int> &nums){
            sort(nums.begin(), nums.end());
            vector<vector<int>> ans(1, vector<int>(1, nums[0]));
            int nxt = 1;
            for (int i = 1; i < nums.size(); i++){
                if (nums[i] != nums[i-1]){
                    ans[0].push_back(nums[i]);
                    nxt = 1;
                }
                else{
                    if (nxt >= ans.size()){
                        ans.push_back(vector<int>(1, nums[i]));
                    }
                    else{
                        ans[nxt].push_back(nums[i]);
                    }
                    nxt++;
                }
            }

            return ans;
        }
};

int main(){
    exit(EXIT_SUCCESS);
}

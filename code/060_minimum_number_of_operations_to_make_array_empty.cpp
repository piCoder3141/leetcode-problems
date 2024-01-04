/* 4th January, 2024
 * Problem: Minimum Number of Operations to Make Array Empty ( https://leetcode.com/problems/minimum-number-of-operations-to-make-array-empty )
 * Difficulty: Medium
 * Solution: For each element, there is no answer, if the count of that element is 1. Otherwise, handle 0, 1, 2 mod
 *           respectively.
*/

#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:
        int minOperations(vector<int> &nums){
            int ans = 0, cnt = 1;
            sort(nums.begin(), nums.end());
            nums.push_back(-1);

            for (int i = 1; i < nums.size(); i++){
                if (nums[i] == nums[i-1]) cnt++;
                else{
                    if (cnt == 1) return -1;
                    ans += (cnt + 2) / 3; // Ceiling
                    cnt = 1;
                }
            }

            return ans;
        }
};

int main(){
    exit(EXIT_SUCCESS);
}

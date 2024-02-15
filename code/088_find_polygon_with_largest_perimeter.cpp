/* 15th February, 2024
 * Problem: Find Polygon With Largset Perimeter ( https://leetcode.com/problems/find-polygon-with-largest-permieter )
 * Difficulty: Medium
 * Solution: Sort the array and compute prefix sums. Find the last element whose value is less than the sum of the 
 *           elements before it. Return the sum of the elements up to this number.
*/

#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:
        long long largestPerimeter(vector<int> &nums){
            sort(nums.begin(), nums.end());
            int n = nums.size();
            vector<long long> pref_sum(n); pref_sum[0] = nums[0];
            for (int i = 1; i < n; i++) pref_sum[i] = pref_sum[i-1] + nums[i];

            for (int i = n-1; i >= 2; i--){
                if (nums[i] < pref_sum[i-1]) return pref_sum[i];
            }

            return -1;
        }
};

int main(){
    exit(EXIT_SUCCESS);
}

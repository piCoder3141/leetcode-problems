/* 22nd October, 2023
 * Problem: Maximum Score of a Good Subarray ( https://leetcode.com/problems/maximum-score-of-a-good-subarray ) 
 * Difficulty: Hard
 * Solution: There are only finite values of the minimum that are possible. Compute the answer for each minimum. 
*/

#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:
        int maximumScore(vector<int> &nums, int k){
            int n = nums.size();
            vector<int> a = nums;
            for (int i = k-1; i >= 0; i--){
                a[i] = min(a[i], a[i+1]);
            }
            for (int i = k+1; i < n; i++){
                a[i] = min(a[i], a[i-1]);
            }

            int ans = a[k];
            for (int i = 0; i < k; i++){
                if ((i > 0) && (a[i] == a[i-1])) continue;
                int x = a[i];
                int ub = upper_bound(a.begin() + k, a.end(), x, greater<int>()) - a.begin() - 1;
                ans = max(x * (ub - i + 1), ans);
            }

            for (int i = n-1; i > k; i--){
                if ((i < n-1) && (a[i] == a[i+1])) continue;
                int x = a[i];
                int lb = lower_bound(a.begin(), a.begin() + k, x) - a.begin();
                ans = max(x * (i - lb + 1), ans);
            }

            return ans;
        }
};

int main(){
    Solution solver;
    vector<int> nums{1, 4, 3, 7, 4, 5};
    cout << solver.maximumScore(nums, 3) << '\n';
    exit(EXIT_SUCCESS);
}

/* 26th October, 2023
 * Problem: Binary Trees with Factors ( https://leetcode.com/problems/binary-trees-with-factors ) 
 * Difficulty: Medium
 * Solution: Dynamic Programming.
*/

#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:
        int numFactoredBinaryTrees(vector<int>& a){
            const int MOD = 1e9 + 7;
            sort(a.begin(), a.end());
            int ans = 0, n = a.size();
            map<int, int> trees;

            for (int i = 0; i < n; i++){
                int curr = 1;
                for (int j = 0; j < i; j++){
                    if (a[i] % a[j] == 0){
                        curr = (curr + ((1ll * trees[a[j]] * trees[a[i] / a[j]]) % MOD)) % MOD;
                    }
                }
                trees[a[i]] = curr;
                ans = (ans + curr) % MOD;
            }

            return ans;
        }
};

int main(){
    Solution solver;
    vector<int> nums={2, 4, 5, 10};
    cout << solver.numFactoredBinaryTrees(nums) << '\n';
    exit(EXIT_SUCCESS);
}

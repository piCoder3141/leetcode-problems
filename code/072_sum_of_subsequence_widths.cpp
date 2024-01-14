/* 13th January, 2024
 * Problem: Sum of Subsequence Widths (https://leetcode.com/problems/sum-of-subsequence-widths/ )
 * Difficulty: Hard
 * Solution: It is enough to find the sum of maximums and minimums of all non-empty subsequnces.
 *           To find sum of maximums, notice that the smallest element can be the maximum of only the subsequences
 *           with only that element in it. 
 *           Sort the array and as you iterate through the elements, compute the 
*/

#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:
        const int MOD = 1e9 + 7;
        long long pow(long long x, long long y){
            int ret = 1;
            while (y > 0){
                if (y&1) ret = (ret * x) % MOD;
                x = (x*x) % MOD;
                y >>= 1;
            }

            return ret;
        }

        int sumSubseqWidths(vector<int> &nums){
            map<int, int> mp;
            for (int &d: nums) mp[d]++;
            int mx_sum = 0, mn_sum = 0, sz = 0;

            for (auto &[k, v]: mp){
                int add = (1ll * k * ((pow(2, sz) * (pow(2, v) - 1 + MOD)) % MOD)) % MOD;
                mx_sum = (mx_sum + add) % MOD;
                sz += v;
            }

            sz = 0;
            for (auto it = mp.rbegin(); it != mp.rend(); it++){
                int k = it->first, v = it->second;
                int add = (1ll * k * ((pow(2, sz) * (pow(2, v) - 1 + MOD)) % MOD)) % MOD;
                mn_sum = (mn_sum + add) % MOD;
                sz += v;
            }

            int ans = (mx_sum - mn_sum + MOD) % MOD;

            return ans;
        }
};

int main(){
    exit(EXIT_SUCCESS);
}

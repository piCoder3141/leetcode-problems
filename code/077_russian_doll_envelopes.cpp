/* 21st January, 2024
 * Problem: Russian Doll Envelopes ( https://leetcode.com/problems/russian-doll-envelopes )
 * Difficulty: Hard
 * Solution: Sort by increasing width and decreasing height. Compute LIS of the resultant height sequence.
*/

#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:
        int maxEnvelopes(vector<vector<int>> &envelopes){
            sort(envelopes.begin(), envelopes.end(), [&](const vector<int> &a, const vector<int> &b){
                    if (a[0] == b[0]) return a[1] > b[1];
                    return a[0] < b[0];
                    });

            vector<int> lis;
            for (auto &env: envelopes){
                int lb = lower_bound(lis.begin(), lis.end(), env[1]) - lis.begin();
                if (lb == lis.size()) lis.push_back(env[1]);
                else lis[lb] = env[1];
            }

            return lis.size();
        }
};

int main(){
    exit(EXIT_SUCCESS);
}

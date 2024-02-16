/* 16th February, 2024
 * Problem: Least Number of Unique Integers after K Removals ( https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals )
 * Difficulty: Medium
 * Solution: 
*/

#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:
        int findLeastNumOfUniqueInts(vector<int> &a, int k){
            unordered_map<int, int> mp;
            for (int &d: a) mp[d]++;

            vector<pair<int, int>> count_key_pairs;
            for (auto &[k, v]: mp) count_key_pairs.push_back({v, k});

            sort(count_key_pairs.begin(), count_key_pairs.end());
            int n = count_key_pairs.size();
            for (int i = 0; i < n; i++){
                if (count_key_pairs[i].first > k) return n-i;
                k -= count_key_pairs[i].first;
            }

            return 0;
        }
};

int main(){
    exit(EXIT_SUCCESS);
}

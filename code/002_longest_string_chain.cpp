/* 23rd September, 2023
 * Problem: Longest String Chain ( https://leetcode.com/problems/longest-string-chain )
 * Difficulty: Medium
 * Solution: Sort the array of strings by their length. Iterate through the array and update the maximum possible
 *           chain length up to the current string. 
*/

#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:
        int longestStrChain(vector<string>& words){
            map<string, int> mp;
            sort(words.begin(), words.end(), [&](string a, string b){
                    return a.length() < b.length();
                });
            int ans = 0;

            for (string w: words){
                int m = w.length();
                int curr_max = 0;
                for (int i = 0; i < m; i++){
                    string new_word = w.substr(0, i) + w.substr(i+1);
                    if (mp.find(new_word) != mp.end()) curr_max = max(curr_max, mp[new_word]);
                }
                mp[w] = curr_max + 1;
                ans = max(ans, curr_max + 1);
            }

            return ans;
        }
};

int main(){
    Solution solver;
    vector<string> input{"a","b","ba","bca","bda","bdca"};
    cout << solver.longestStrChain(input) << "\n";
    exit(EXIT_SUCCESS);
}

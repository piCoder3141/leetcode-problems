/* 9th November, 2023.
 * Problem: Count Number of Homogenous Substrings ( https://leetcode.com/problems/count-number-of-homogenous-substrings ) 
 * Difficulty: Medium
 * Solution: Sum up l(l+1)/2 where l is the length of each run in the string.
*/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countHomogenous(string s){
        int ans = 1, run = 1;
        const int MOD = 1e9 + 7;
        for (int i = 1; i < s.size(); i++){
            ans += (s[i] == s[i-1]) ? ++run: (run = 1);
            if (ans >= MOD) ans -= MOD;
        }
        return ans;
    }
};

int main(){
    Solution solver;
    cout << solver.countHomogenous("abbcccaa");
    exit(EXIT_SUCCESS);
}

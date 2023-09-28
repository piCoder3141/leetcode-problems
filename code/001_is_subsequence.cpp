/* 22nd September, 2023
 * Problem: Is Subsequence ( https://leetcode.com/problems/is-subsequence )
 * Difficulty: Easy
 * Solution: Iterate through 's' and greedily find the matching character in 't'.
*/

#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:
        bool isSubsequence(string s, string t){
            int n = s.length(), m = t.length();
            bool ans = true;
            int j = 0;
            for (int i = 0; i < n; i++){
                while((j < m) && (s[i] != t[j])) j++;
                if (j == m) ans = false;
                j++;
            }

            return ans;
        }
};

int main(){
    Solution solver;
    cout << solver.isSubsequence("abc", "ahdfdbdfac") << "\n";
    exit(EXIT_SUCCESS);
}

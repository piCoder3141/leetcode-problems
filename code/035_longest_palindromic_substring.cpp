/* 27th October, 2023
 * Problem: Longest Palindromic Substring ( https://leetcode.com/problems/longest-palindromic-substring ) 
 * Difficulty: Medium
 * Solution: Expand from center of every possible palindrome.
*/

#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:
        string longestPalindrome(string s){
            int n = s.length(), longest=0;
            string ans = "";

            for (int i = 0; i < n; i++){
                int lo = i, hi = i;
                while((lo > 0) && (hi < n-1) && (s[lo-1] == s[hi+1])) lo--, hi++;
                if (hi - lo + 1 > longest){
                    longest = hi - lo + 1;
                    ans = s.substr(lo, hi - lo + 1);
                }
            }

            for (int i = 0; i < n-1; i++){
                int lo = i, hi = i+1;
                if (s[lo] != s[hi]) continue;
                while((lo > 0) && (hi < n-1) && (s[lo-1] == s[hi+1])) lo--, hi++;
                if (hi - lo + 1 > longest){
                    longest = hi - lo + 1;
                    ans = s.substr(lo, hi - lo + 1);
                }
            }

            return ans;
        }
};

int main(){
    Solution solver;
    cout << solver.longestPalindrome("babad") << '\n';
    exit(EXIT_SUCCESS);
}

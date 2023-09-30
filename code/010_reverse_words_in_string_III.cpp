/* 1st October, 2023
 * Problem: Reverse Words in a String III ( https://leetcode.com/problems/reverse-words-in-a-string-iii )
 * Difficulty: Easy
 * Solution: Split by spaces and reverse each word and add to answer string.
*/

#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:
        string reverseWords(string s){
            string ans = "", curr = "";
            for (char c: s){
                if (c == ' '){
                    reverse(curr.begin(), curr.end());
                    ans += curr;
                    ans += ' ';
                    curr = "";
                }
                else curr += c;
            }
            reverse(curr.begin(), curr.end());
            ans += curr;
            
            return ans;
        }
};

int main(){
    Solution solver;
    cout << solver.reverseWords("Let's take LeetCode contest") << "\n";
    exit(EXIT_SUCCESS);
}

/* 25th September, 2023
 * Problem: Remove Duplicate Letters ( https://leetcode.com/problems/remove-duplicate-letters )
 * Difficulty: Medium
 * Solution: Create an empty stack. Iteratively add characters into the stack if they are bigger than the top element.
 *           Pop elements if they are bigger than the current element and have extra characters left. 
*/

#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:
        string removeDuplicateLetters(string s){
            int char_count[26] = {0};
            bool used[26] = {0};
            for (char c: s) char_count[c-'a']++;
            string ans = "";
            for (char c: s){
                if (used[c-'a']){
                    char_count[c-'a']--; continue;
                }
                while(!ans.empty() && ans.back() > c){
                    if (char_count[ans.back() - 'a'] > 0){
                        used[ans.back() - 'a'] = false;
                        ans.pop_back();
                    }
                    else break;
                }
                ans += c;
                used[c-'a'] = true;
                char_count[c-'a']--;
            }

            return ans;
        }
};

int main(){
    Solution solver;
    cout << solver.removeDuplicateLetters("bbaca") << "\n";
    exit(EXIT_SUCCESS);
}

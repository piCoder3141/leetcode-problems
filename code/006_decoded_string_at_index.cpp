/* 26th September, 2023
 * Problem: Decoded String at Index ( https://leetcode.com/problems/decoded-string-at-index )
 * Difficulty: Medium
 * Solution: Compute strlen[i] := Length of decoding string up to index i of the decoded string.
 *           Recursively find the kth letter in the decoded string using strlen. 
 *           Base case :- If the index corresponding to the kth letter in the decoded string is a letter, return it.
*/

#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:
        string solve(string &s, int k, vector<long long> &strlen, vector<bool> &is_letter){
            int lb = lower_bound(strlen.begin(), strlen.end(), k) - strlen.begin();
            if (is_letter[lb]) return string(1, s[lb]);
            return solve(s, ((k-1) % strlen[lb-1]) + 1, strlen, is_letter);
        }

        string decodeAtIndex(string s, int k){
            int n = s.length();
            vector<long long> strlen(n);
            vector<bool> is_letter(n, true);
            strlen[0] = 1;
            for (int i = 1; i < n; i++){
                if ((s[i] >= '0') && (s[i] <= '9')){
                    strlen[i] = strlen[i-1] * (s[i]-'0');
                    is_letter[i] = false;
                }
                else strlen[i] = strlen[i-1] + 1;
            }

            return solve(s, k, strlen, is_letter);
        }
};

int main(){
    Solution solver;
    cout << solver.decodeAtIndex("a2b3c4d5e6f7g8h9", 9) << "\n";
    exit(EXIT_SUCCESS);
}

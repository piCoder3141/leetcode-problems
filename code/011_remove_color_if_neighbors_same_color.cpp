/* 2nd October, 2023
 * Problem: Remove Colored Pieces if Both Neighbors are the Same Colors ( https://leetcode.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color ) 
 * Difficulty: Medium
 * Solution: For each run of 'A' or 'B', the number of pieces they can remove is max(lenght(Run) - 2, 0).
 *           Compute the number of pieces 'A' and 'B' can remove. Return true if 'A' can remove more pieces.
*/

#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:
        bool winnerOfGame(string s){
            int cnt = 0, len = 1;
            char last = s[0];
            int n = s.length();

            for (int i = 1; i < n; i++){
                if (s[i] == last){
                    len++;
                }
                else{
                    cnt += max(len-2, 0) * ((last == 'A') ? 1 : -1);
                    last = s[i];
                    len = 1;
                }
            }
            cnt += max(len-2, 0) * ((last == 'A') ? 1 : -1);
            return (cnt > 0);
        }
};

int main(){
    Solution solver;
    cout << solver.reverseWords("AABBAAAAABBBA") << "\n";
    exit(EXIT_SUCCESS);
}

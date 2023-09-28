/* 25th September, 2023
 * Problem: Find the Difference ( https://leetcode.com/problems/find-the-difference )
 * Difficulty: Easy
 * Solution: Count every character in both strings, return the character whose count is different.
*/

#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:
        char findTheDifference(string s, string t){
            int charCount[26] = {0};
            for (char c: s) charCount[c-'a']++;
            for (char c: t) charCount[c-'a']--;

            for (int i = 0; i < 26; i++){
                if (charCount[i] != 0) return 'a' + i;
            }

            return ' ';
        }
};

int main(){
    Solution solver;
    cout << solver.champagneTower(100009, 33, 17) << "\n";
    exit(EXIT_SUCCESS);
}

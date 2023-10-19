/* 19th October, 2023
 * Problem: Backspace String Compare ( https://leetcode.com/problems/backspace-string-compare )
 * Difficulty: Easy
 * Solution: Iterate through the string backwards and get next valid character in both strings.
*/

#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:
        bool backspaceCompare(string s, string t){
            const char BACK = '#';
            int i = s.length()-1, j = t.length()-1, cnt = 0;
            while (true){
                while((i >= 0) && ((s[i] == BACK) || (cnt > 0))){
                    if (s[i] == BACK) cnt++;
                    else cnt--;
                    i--;
                }
                cnt = 0;

                while((j >= 0) && ((t[j] == BACK) || (cnt > 0))){
                    if (t[j] == BACK) cnt++;
                    else cnt--;
                    j--;
                }
                cnt = 0;

                if ((i == -1) && (j == -1)) return true;
                if ((i == -1) || (j == -1)) return false;
                if (s[i] != t[j]) return false;
                i--; j--;
            }

            return true;
        }
};

int main(){
    Solution solver;
    cout << solver.backspaceCompare("ab#c", "ad#c") << '\n';
    exit(EXIT_SUCCESS);
}

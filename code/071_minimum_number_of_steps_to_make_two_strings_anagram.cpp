/* 13th January, 2024
 * Problem: Minimum Number of Steps to Make Two Strings Anaagram ( https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/ )
 * Difficulty: Medium
 * Solution: Create a array to count the characters of 's'. Iterate through the characters of 't' and decrement the
 *           count of in the array where the count is greater than 0. The sum of the array after the operation is the
 *           answer.
*/

#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:
        int minSteps(string s, string t){
            int n = s.length();
            int count[26] = {0};

            for (char &c: s) count[c-'a']++;
            for (char &c: t) count[c-'a'] = max(count[c-'a']-1, 0);

            return accumulate(count, count + 26, 0);
        }
};

int main(){
    exit(EXIT_SUCCESS);
}

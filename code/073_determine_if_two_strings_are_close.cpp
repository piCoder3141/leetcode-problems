/* 14th January, 2024
 * Problem: Determine if Two Strings are Close ( https://leetcode.com/problems/determine-if-two-strings-are-close/ )
 * Difficulty: Medium
 * Solution: 1. Create the 26-length array of character counts and check if these arrays are equal after sorting.
 *           2. Check that the set of characters in both strings are same.
*/

#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:
        bool closeStrings(string word1, string word2){
            vector<int> c1(26), c2(26);
            set<char> s1(word1.begin(), word1.end()), s2(word2.begin(), word2.end());
            if (s1 != s2) return false;

            for (char &c: word1) c1[c-'a']++;
            for (char &c: word2) c2[c-'a']++;
            
            sort(c1.begin(), c1.end());
            sort(c2.begin(), c2.end());

            return (c1 == c2);
        }
};

int main(){
    exit(EXIT_SUCCESS);
}

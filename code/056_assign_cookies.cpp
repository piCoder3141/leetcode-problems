/* 1st January, 2024
 * Problem: Assign Cookies ( https://leetcode.com/problems/assign-cookies )
 * Difficulty: Easy
 * Solution: Sort the greed and the size array in ascending order. Assign sequentially until not possible.
*/

#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:
        int findContentChildren(vector<int>& g, vector<int>& s){
            sort(g.begin(), g.end());
            sort(s.begin(), s.end());
            int sn = s.size(), gn = g.size();

            int j = 0;
            for (int i = 0; i < gn; i++){
                while ((j < sn) && (s[j] < g[i])) j++;
                if (j == sn) return i;
                j++;
            }

            return gn;
        }
};

int main(){
    exit(EXIT_SUCCESS);
}

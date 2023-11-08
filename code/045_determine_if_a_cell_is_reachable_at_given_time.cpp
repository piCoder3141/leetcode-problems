/* 8th November, 2023.
 * Problem: Determine if a Cell is Reachable at a Given Time ( https://leetcode.com/problems/determine-if-a-cell-is-reachable-at-a-given-time ) 
 * Difficulty: Medium
 * Solution: Elementary logic.
*/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t){
        int dist = max(abs(sx - fx), abs(sy - fy));
        if (dist == 0) return t != 1;
        else return t >= dist;
    }
};

int main(){
    Solution solver;
    cout << solver.isReachableAtTime(1, 2, 1, 2, 1);
    exit(EXIT_SUCCESS);
}

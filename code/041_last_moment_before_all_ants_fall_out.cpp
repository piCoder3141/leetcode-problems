/* 3rd November, 2023.
 * Problem: Last Moment Before All Ants Fall Out of a Plank ( https://leetcode.com/problems/last-moment-before-all-ants-fall-out-of-a-plank ) 
 * Difficulty: Medium
 * Solution: The answer would not change if on collision, the ants could pass through each other. Therfore, 
 *           compute max(left+1, n-right + 1)
*/

#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:
        int getLastMoment(int n, vector<int> &left, vector<int>&right){
            left.push_back(-1);
            right.push_back(n+1);
            int mx_left = *max_element(left.begin(), left.end());
            int mn_right = *min_element(right.begin(), right.end());
            return max(mx_left, n - mn_right);
        }
};

int main(){
    Solution solver;
    vector<int> left{3, 4}, right{0, 1};
    cout << solver.getLastMoment(4, left, right);
    exit(EXIT_SUCCESS);
}

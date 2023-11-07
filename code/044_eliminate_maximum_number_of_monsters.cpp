/* 7th November, 2023.
 * Problem: Eliminate Maximum Number of Monsters ( https://leetcode.com/problems/eliminate-maximum-number-of-monsters ) 
 * Difficulty: Medium
 * Solution: Sort by time to reach the city. Return first index where time[i] < (i+1). `n` otherwise.
*/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int eliminateMaximum(vector<int> &dist, vector<int> &speed){
        int n = dist.size();
        vector<int> time(n);
        for (int i = 0; i < n; i++) time[i] = (dist[i] + speed[i] - 1) / speed[i];

        sort(time.begin(), time.end());

        int ans = 0;
        for (int i = 0; i < n; i++){
            if (time[i] < (i+1)) return ans;
            ans++;
        }
        return ans;
    }
};

int main(){
    Solution solver;
    vector<int> dist{3, 2, 4}, speed{5, 3, 2};
    cout << solver.eliminateMaximum(dist, speed);
    exit(EXIT_SUCCESS);
}

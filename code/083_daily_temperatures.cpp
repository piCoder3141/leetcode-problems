/* 31st January, 2024
 * Problem: Daily Temperatures ( https://leetcode.com/problems/daily-temperatures )
 * Difficulty: Medium
 * Solution: Use stack to get index of next larger element.
*/

#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:
        vector<int> dailyTemperatures(vector<int> &temperatures){
            int n = temperatures.size();
            vector<int> next_larger(n, n), ans(n, 0);

            for (int i = n-2; i >= 0; i--){
                int j = i+1;
                while((j < n) && (temperatures[j] <= temperatures[i])) j = next_larger[j];
                next_larger[i] = j;
            }

            for (int i = 0; i < n; i++){
                ans[i] = (next_larger[i] == n) ? 0: next_larger[i] - i;
            }

            return ans;
        }
};

int main(){
    exit(EXIT_SUCCESS);
}

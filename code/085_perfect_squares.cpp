/* 8th February, 2024
 * Problem: Perfect Squares ( https://leetcode.com/problems/perfect-squares )
 * Difficulty: Medium
 * Solution: Fibonacci like dp.
*/

#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:
        int numSquares(int n){
            vector<int> perfect_squares;
            for (int i = 1; i*i <= n; i++) perfect_squares.push_back(i*i);

            vector<int> dp(n+1, INT_MAX);
            dp[0] = 0;
            for (int i = 1; i <= n; i++){
                for (int &d : perfect_squares){
                    if (d > i) break;
                    dp[i] = min(dp[i], dp[i-d] + 1);
                }
            }

            return dp[n];
        }
};

int main(){
    exit(EXIT_SUCCESS);
}

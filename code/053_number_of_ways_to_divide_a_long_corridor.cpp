/* 28th November, 2023.
 * Problem: Number of Ways to Divide a Long Corridor ( https://leetcode.com/problems/number-of-ways-to-divide-a-long-corridor ) 
 * Difficulty: Hard
 * Solution: For each divider, store the lower and upper bound of its possible positions. Multiply all possibilities.
*/

#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:
        int numberOfWays(string corridor){
            const int MOD = 1e9 + 7;
            int s_count = 0;
            bool atleast_one = false;
            int ans = 1, prev = -1;

            int n = corridor.length();
            for (int i = 0; i < n; i++){
                if (corridor[i] == 'P') continue;
                s_count++; atleast_one = true;
                if (s_count == 2) prev = i;
                else if (s_count == 3){
                    ans = (1ll * ans * (i - prev)) % MOD;
                    s_count = 1;
                }
            }

            return ((s_count & 1) | (!atleast_one)) ? 0: ans;
        }
};

int main(){
    exit(EXIT_SUCCESS);
}

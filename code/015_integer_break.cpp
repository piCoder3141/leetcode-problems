/* 6th October, 2023
 * Problem: Integer Break ( https://leetcode.com/problems/integer-break ) 
 * Difficulty: Medium
 * Solution: Iterate from k = 2 to n/2, and return the maximum product.
*/

#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:
        int compute(int n, int k){
            int base = n/k, rem = n%k;
            return ((int) pow(base, k - rem)) * ((int) pow(base+1, rem));
        }
        int integerBreak(int n){
            if (n <= 3) return n-1;
            int ans = 1;
            for (int k = 2; k <= n/2; k++){
                ans = max(ans, compute(n, k));
            }

            return ans;
        }
};

int main(){
    Solution solver;
    cout << solver.integerBreak(58) << "\n";
    exit(EXIT_SUCCESS);
}

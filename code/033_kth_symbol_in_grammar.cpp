/* 25th October, 2023
 * Problem: K-th Symbol in Grammer ( https://leetcode.com/problems/k-th-symbol-in-grammar ) 
 * Difficulty: Medium
 * Solution: The symbol changes from one row to the other when there is m -> 2*m+1; Count number of bits in binary
 *           representation of `k`.
*/

#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:
        int kthGrammar(int n, int k){
            return __builtin_popcount(k-1) & 1;
        }
};

int main(){
    Solution solver;
    cout << solver.kthGrammar(2, 2) << '\n';
    exit(EXIT_SUCCESS);
}

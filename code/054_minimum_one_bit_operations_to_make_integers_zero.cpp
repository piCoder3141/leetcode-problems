/* 30th November, 2023.
 * Problem: Minimum One Bit Operations to Make Integers Zero ( https://leetcode.com/problems/minimum-one-bit-operations-to-make-integers-zero )
 * Difficulty: Hard
 * Solution: Gray Code
*/

#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:
        int minimumOneBitOperations(int n){
            int res = n;
            while (n > 0){
                n >>= 1;
                res ^= n;
            }
            return res;
        }
};

int main(){
    exit(EXIT_SUCCESS);
}

/* 23rd October, 2023
 * Problem: Power of Four ( https://leetcode.com/problems/power-of-four ) 
 * Difficulty: Easy
 * Solution: Should have the binary representation of the form 000...1...0000 where `1` is in an even position.
*/

#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:
        bool isPowerOfFour(int n){
            return (n > 0) && ((n & (n-1)) == 0) && ((n & 0x55555555) == n);
        }
};

int main(){
    Solution solver;
    cout << solver.isPowerOfFour(16) << '\n';
    exit(EXIT_SUCCESS);
}

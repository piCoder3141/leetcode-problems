/* 3rd January, 2024
 * Problem: Check if Point is Reachable ( https://leetcode.com/problems/check-if-point-is-reachable )
 * Difficulty: Hard
 * Solution: 
*/

#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:
        bool isReachable(int x, int y){
            int gcd = __gcd(x, y);
            return gcd && (!(gcd & (gcd-1)));
        }
};

int main(){
    exit(EXIT_SUCCESS);
}

/* 29th October, 2023
 * Problem: Poor Pigs ( https://leetcode.com/problems/poor-pigs ) 
 * Difficulty: Hard
 * Solution: Suppose we have `p` pigs and we conduct `T` tests. There are a total of `(T+1)^p outcomes. 
 *           To find the poisonous bucket, we need `(T+1)^p >= buckets`
*/

#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:
        int poorPigs(int buckets, int minutesToDie, int minutesToTest){
            int T = minutesToTest / minutesToDie;
            return ceil( log(buckets) / log(T+1) );
        }
};

int main(){
    Solution solver;
    cout << solver.poorPigs(4, 15, 30) << '\n';
    exit(EXIT_SUCCESS);
}

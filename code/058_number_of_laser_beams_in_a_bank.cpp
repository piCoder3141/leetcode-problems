/* 3rd January, 2024
 * Problem: Number of Laser Beams in a Bank (https://leetcode.com/problems/number-of-laser-beams-in-a-bank )
 * Difficulty: Medium
 * Solution: Multiply the number of lasers in each consecutive rows with non-zero security devices.
*/

#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:
        int numberOfBeams(vector<string>& bank){
            int ans = 0, prev = 0;
            for (string &row: bank){
                int devices = 0;
                for (char &c: row) devices += (c == '1');
                ans += devices * prev;
                if (devices > 0) prev = devices;
            }

            return ans;
        }
};

int main(){
    exit(EXIT_SUCCESS);
}

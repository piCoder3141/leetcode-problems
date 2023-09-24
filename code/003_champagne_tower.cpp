/* 24th September, 2023
 * Problem: Champagne Tower ( https://leetcode.com/problems/champagne-tower/description )
 * Difficulty: Medium
 * Solution: Simulate the process by initially assigning all the champagne to the topmost cup.
 *           Iteratively, divide the extra champagne in the children of the current cup. 
*/

#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:
        double champagneTower(int poured, int row, int glass){
            double glasses[101][101] = {0.0};
            glasses[0][0] = poured;
            for (int i = 0; i <= row; i++){
                for (int j = 0; j <= i; j++){
                    double extra = max(glasses[i][j] - 1.0, 0.0);
                    glasses[i][j] = glasses[i][j] - extra;
                    glasses[i+1][j] += extra / 2.0;
                    glasses[i+1][j+1] += extra / 2.0;
                }
            }
            return glasses[row][glass];
        }
};

int main(){
    Solution solver;
    cout << solver.champagneTower(100009, 33, 17) << "\n";
    exit(EXIT_SUCCESS);
}

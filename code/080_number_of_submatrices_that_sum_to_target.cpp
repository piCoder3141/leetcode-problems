/* 28th January, 2024
 * Problem: Number of Submatrices That Sum to Target ( https://leetcode.com/problems/number-of-submatrices-that-sum-to-target )
 * Difficulty: Hard
 * Solution: Fix two rows and then reduce the problem to a 1D array. 
*/

#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:
        int numSubmatrixSumTarget(vector<vector<int>> &matrix, int target){
            int m = matrix.size(), n = matrix[0].size();

            vector<vector<int>> rowCum(m+1, vector<int>(n));
            for (int i = 0; i < m; i++){
                for (int j = 0; j < n; j++){
                    rowCum[i+1][j] = rowCum[i][j] + matrix[i][j];
                }
            }

            int ans = 0;
            for (int r1 = 0; r1 < m; r1++){
                for (int r2 = r1+1; r2 <= m; r2++){
                    map<int, int> mp; mp[0] = 1;
                    int prev = 0;
                    for (int j = 0; j < n; j++){
                        int x = prev + rowCum[r2][j] - rowCum[r1][j];
                        ans += mp[x-target];
                        mp[x]++;
                        prev = x;
                    }
                }
            }

            return ans;
        }
};

int main(){
    exit(EXIT_SUCCESS);
}

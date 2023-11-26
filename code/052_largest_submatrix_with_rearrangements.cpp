/* 26th November, 2023.
 * Problem: Largest Submatrix with Rearrangements ( https://leetcode.com/problems/largest-submatrix-with-rearrangements ) 
 * Difficulty: Medium
 * Solution: Withouth loss of generality, we can assume that the submatrix has its left end in the first column.
 *           Iterate over each row, construct the largest submatrix assuming this row is the top row the submatrix.
*/

#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:
        int largestSubmatrix(vector<vector<int>> &mat){
            vector<vector<int>> suff = mat;
            int n = mat.size(), m = mat[0].size();
            for (int i = n-2; i >= 0; i--){
                for (int j = 0; j < m; j++){
                    suff[i][j] = (mat[i][j] == 0) ? 0: suff[i+1][j] + 1;
                }
            }

            int ans = 0;
            for (int i = 0; i < n; i++){
                sort(suff[i].rbegin(), suff[i].rend());

                for (int j = 0; j < m; j++){
                    ans = max(ans, suff[i][j] * (j+1));
                }
            }

            return ans;
        }
};

int main(){
    exit(EXIT_SUCCESS);
}

/* 14th December, 2023.
 * Problem: Difference Between Ones and Zeroes in Row and Column ( https://leetcode.com/problems/difference-between-ones-and-zeros-in-row-and-column )
 * Difficulty: Medium
 * Solution: Direct implementation
*/

#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:
        vector<vector<int>> onesMinusZeros(vector<vector<int>> &grid){
            int n = grid.size(), m = grid[0].size();
            vector<vector<int>> ans(n, vector<int>(m));
            vector<int> onesRows(n), onesCols(m);

            for (int i = 0; i < n; i++){
                for (int j = 0; j < m; j++){
                    if (grid[i][j]) onesRows[i]++, onesCols[j]++;
                }
            }

            for (int i = 0; i < n; i++){
                for (int j = 0; j < m; j++){
                    ans[i][j] = 2 * (onesRows[i] + onesCols[j]) - (m + n);
                }
            }

            return ans;
        }
};

int main(){
    exit(EXIT_SUCCESS);
}

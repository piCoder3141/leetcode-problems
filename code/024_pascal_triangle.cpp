/* 16th October, 2023
 * Problem: Pascal's Triangle ( https://leetcode.com/problems/pascals-triangle-ii )
 * Difficulty: Easy
 * Solution: Follow the generation algorithm
*/

#include<bits/stdc++.h>

using namespace std;


class Solution{
    public:
        vector<int> getRow(int row){
            vector<int> ans(1, 1);
            vector<int> tmp;

            for (int r = 1; r <= row; r++){
                tmp = ans;
                ans.clear();
                ans.push_back(1);
                for (int i = 0; i < tmp.size()-1; i++){
                    ans.push_back(tmp[i] + tmp[i+1]);
                }
                ans.push_back(1);
            }

            return ans;
        }
};

int main(){
    Solution solver;
    vector<int> ans = solver.getRow(10);
    for (int &d: ans) cout << d << ' ';
    cout << '\n';
    exit(EXIT_SUCCESS);
}

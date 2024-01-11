/* 11th January, 2024
 * Problem: Maximum Difference Between Node and Ancestor ( https://leetcode.com/problems/maximum-difference-between-node-and-ancestor )
 * Difficulty: Medium
 * Solution: DFS
*/

#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:
        int ans = 0;
        const int MX = 1e5;
        const int MN = 0;

        pair<int, int> dfs(TreeNode* root){
            if (!root) return {MX, MN};
            pair<int, int> ret = {root->val, root->val};
            pair<int, int> p = dfs(root->left);
            ans = max({ans, root->val - p.first, p.second - root->val});
            ret = {min(ret.first, p.first), max(ret.second, p.second)};

            p = dfs(root->right);
            ans = max({ans, root->val - p.first, p.second - root->val});
            ret = {min(ret.first, p.first), max(ret.second, p.second)};
            
            return ret;
        }

        int maxAncestorDiff(TreeNode* root){
            dfs(root);
            return ans;
        }
};

int main(){
    exit(EXIT_SUCCESS);
}

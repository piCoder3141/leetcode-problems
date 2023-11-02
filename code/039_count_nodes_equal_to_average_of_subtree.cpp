/* 2nd November, 2023.
 * Problem: Count Nodes Equal to Average of Subtree ( https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree ) 
 * Difficulty: Medium
 * Solution: Tree DP.
*/

#include<bits/stdc++.h>

using namespace std;

/*
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x) left(left), right(right) {}
 * }
 */

class Solution{
    public:
        int ans = 0;
        int averageOfSubtree(TreeNode* root){
            if (root == nullptr) return 0;
            pair<int, int> p = dfs(root);
            return ans;
        }

        pair<int, int> dfs(TreeNode* root){
            pair<int, int> ret{root->val, 1};
            if (root->left){
                pair<int, int> p = dfs(root->left);
                ret.first += p.first;
                ret.second += p.second;
            }
            if (root->right){
                pair<int, int> p = dfs(root->right);
                ret.first += p.first;
                ret.second += p.second;
            }

            if (ret.first / ret.second == root->val) ans++;
            return ret;
        }
};

int main(){
    exit(EXIT_SUCCESS);
}

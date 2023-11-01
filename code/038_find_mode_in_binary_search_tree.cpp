/* 1st November, 2023.
 * Problem: Find Mode in Binary Search Tree ( https://leetcode.com/problems/find-mode-in-binary-search-tree ) 
 * Difficulty: Easy
 * Solution: Inorder traversal of the tree.
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
        vector<int> ans;
        int curr_num = INT_MAX;
        int curr_streak = 0, max_streak = 0;
        vector<int> findMode(TreeNode* root){
            dfs(root);
            return ans;
        }

        void dfs(TreeNode* root){
            if (root == nullptr) return;
            dfs(root->left);

            int num = root->val;
            if (curr_num == num){
                curr_streak++;
            }
            else{
                curr_num = num;
                curr_streak = 1;
            }
            
            if (curr_streak > max_streak){
                ans = {};
                max_streak = curr_streak;
            }

            if (curr_streak == max_streak){
                ans.push_back(curr_num);
            }

            dfs(root->right);
        }
};

int main(){
    exit(EXIT_SUCCESS);
}

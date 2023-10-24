/* 24th October, 2023
 * Problem: Find Largest Value in Each Tree Row (https://leetcode.com/problems/find-largest-value-in-each-tree-row ) 
 * Difficulty: Medium
 * Solution: Breadth-First Search
*/

#include<bits/stdc++.h>

using namespace std;

/*
 * struct TreeNode{
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(): val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */

class Solution{
    public:
        vector<int> largestValues(TreeNode* root){
            if (root == nullptr) return {};
            vector<int> ans;
            queue<TreeNode*> q;
            q.push(root);
            
            while (!q.empty()){
                int sz = q.size(), mx = INT_MIN;
                for (int itr = 0; itr < sz; itr++){
                    TreeNode* tmp = q.front(); q.pop();
                    mx = max(mx, tmp->val);
                    if (tmp->left) q.push(tmp->left);
                    if (tmp->right) q.push(tmp->right);
                }
                ans.push_back(mx);
            }

            return ans;
        }
};

int main(){
    exit(EXIT_SUCCESS);
}

/* 10th January, 2024
 * Problem: Amount of Time for Binary Tree to be Infected ( https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected )
 * Difficulty: Medium
 * Solution: Convert to an undirected graph and then simple dfs from the 'start' node.
*/

#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:
        static const int MX = 1e5;
        vector<vector<int>> adj = vector<vector<int>>(MX);
        int ans = 0;
        
        void createUndirectedGraph(TreeNode* root){
            if (root == nullptr) return;
            if (root->left){
                adj[root->val - 1].push_back(root->left->val - 1);
                adj[root->left->val - 1].push_back(root->val - 1);
                createUndirectedGraph(root->left);
            }
            if (root->right){
                adj[root->val - 1].push_back(root->right->val - 1);
                adj[root->right->val - 1].push_back(root->val - 1);
                createUndirectedGraph(root->right);
            }
        }

        int dfs(int u, int p){
            int ret = 0;
            for (int &v: adj[u]){
                if (v == p) continue;
                ret = max(ret, dfs(v, u));
            }

            return ret + 1;
        }

        int amountOfTime(TreeNode* root, int start){
            createUndirectedGraph(root);

            return dfs(start-1);
        }
};

int main(){
    exit(EXIT_SUCCESS);
}

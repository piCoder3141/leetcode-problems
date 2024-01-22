/* 22nd January, 2024
 * Problem: Height of Binary Tree After Subtree Removal Queries ( https://leetcode.com/problems/height-of-binary-tree-after-subtree-removal-queries/ )
 * Difficulty: Hard
 * Solution: Compute the height of each node in the tree. Observe that only the nodes on the maximum height path will
 *           affect the tree height on removal. Mark all such nodes. Iterate from the root and obtain height after 
 *           removal of these nodes.
*/

#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:
        static const int MX = 1e5 + 1;
        vector<int> heights, updated_heights;
        vector<bool> marked;

        int dfs(TreeNode* root){
            int height = 0;
            if (root->left){
                height = max(height, 1 + dfs(root->left));
            }
            if (root->right){
                height = max(height, 1 + dfs(root->right));
            }

            return heights[root->val] = height;
        }

        void mark_nodes(TreeNode* root, int prev, int length){
            marked[root->val] = true;

            updated_heights[root->val] = prev;

            int cnt = 0;
            if (root->left && (heights[root->val] == 1 + heights[root->left->val])) cnt += 1;
            if (root->right && (heights[root->val] == 1 + heights[root->right->val])) cnt += 2;

            if (cnt == 1){
                int right_child_height = (root->right) ? heights[root->right->val] + 1 : 0;
                mark_nodes(root->left, max(prev, length + right_child_height), length+1);
            }
            else if (cnt == 2){
                int left_child_height = (root->left) ? heights[root->left->val] + 1 : 0;
                mark_nodes(root->right, max(prev, length + left_child_height), length+1);
            }

            return;

        }

        vector<int> treeQueries(TreeNode* root, vector<int> &queries){
            heights.assign(MX, 0);
            updated_heights.assign(MX, 0);
            marked.assign(MX, false);

            dfs(root);
            mark_nodes(root, 0, 0);

            vector<int> ans;
            for (int &d: queries){
                if (marked[d]){
                    ans.push_back(updated_heights[d]);
                }
                else ans.push_back(heights[root->val]);
            }

            return ans;
        }
};

int main(){
    exit(EXIT_SUCCESS);
}

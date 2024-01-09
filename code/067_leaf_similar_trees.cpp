/* 9th January, 2024
 * Problem: Leaf-Similar Trees ( https://leetcode.com/problems/leaf-similar-trees )
 * Difficulty: Easy
 * Solution: Get leaf sequence of each tree and compare.
*/

#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:
        void getLeafSequence(TreeNode* root, vector<int> &leaf_seq){
            if (root == nullptr) return;
            if ((root->left == nullptr) && (root->right == nullptr)) leaf_seq.push_back(root->val);
            else{
                getLeafSequence(root->left, leaf_seq);
                getLeafSequence(root->right, leaf_seq);
            }
        }

        bool leafSimilar(TreeNode* root1, TreeNode* root2){
            vector<int> leaf_seq1, leaf_seq2;
            getLeafSequence(root1, leaf_seq1);
            getLeafSequence(root2, leaf_seq2);

            return (leaf_seq1 == leaf_seq2);
        }
};

int main(){
    exit(EXIT_SUCCESS);
}

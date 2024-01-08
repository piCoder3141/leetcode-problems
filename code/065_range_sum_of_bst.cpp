/* 8th January, 2024
 * Problem: Range Sum of BST ( https://leetcode.com/problems/range-sum-of-bst )
 * Difficulty: Easy
 * Solution: Standard.
*/

#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:
        int rangeSumBST(TreeNode* root, int low, int high){
            if (root == nullptr) return 0;
            if (root->val > high) return rangeSumBST(root->left, low, high);
            if (root->val < low) return rangeSumBST(root->right, low, high);

            int ans = root->val;
            ans += rangeSumBST(root->left, low, root->val - 1);
            ans += rangeSumBST(root->right, root->val + 1, high);
            
            return ans;
        }
};

int main(){
    exit(EXIT_SUCCESS);
}

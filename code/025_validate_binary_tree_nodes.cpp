/* 17th October, 2023
 * Problem: Validate Binary Tree Nodes ( https://leetcode.com/problems/validate-binary-tree-nodes )
 * Difficulty: Medium
 * Solution: You have to check _ things:
 *           1. There should be exactly one root. 
 *           2. Every node should have at most one parent.
 *           3. All nodes should be reachable from the root.
 *           4. There should be no cycle.
*/

#include<bits/stdc++.h>

using namespace std;


class Solution{
    public:
        bool dfs(int root, vector<bool> &visited, vector<int> &left, vector<int> &right){
            visited[root] = true;
            if (left[root] != -1){
                if (visited[left[root]]) return false;
                dfs(left[root], visited, left, right);
            }
            if (right[root] != -1){
                if (visited[right[root]]) return false;
                dfs(right[root], visited, left, right);
            }

            return true;
        }

        bool validateBinaryTreeNodes(int n, vector<int>& left, vector<int>& right){
            vector<int> leftIn(n, 0), rightIn(n, 0);
            for (int &d : left) if (d != -1) leftIn[d]++;
            for (int &d : right) if (d != -1) rightIn[d]++;

            int root = -1;
            for (int i = 0; i < n; i++){
                if ((leftIn[i] == 0) & (rightIn[i] == 0)){
                    if (root != -1) return false;
                    root = i;
                }
                if (leftIn[i] + rightIn[i] > 1) return false;
            }
            if (root == -1) return false;
            vector<bool> visited(n, false);
            bool dfs_check = dfs(root, visited, left, right);

            bool all_visited = true;
            for (bool b: visited) all_visited &= b;

            return dfs_check & all_visited;
        }
};

int main(){
    Solution solver;
    vector<int> left{1, -1, 3, -1};
    vector<int> right{2, -1, -1, -1};
    cout << solver.validateBinaryTreeNodes(n, left, right) << '\n';
    exit(EXIT_SUCCESS);
}

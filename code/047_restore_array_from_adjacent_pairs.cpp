/* 10th November, 2023.
 * Problem: Restore Array from Adjacent Pairs ( https://leetcode.com/problems/restore-the-array-from-adjacent-pairs ) 
 * Difficulty: Medium
 * Solution: Make a graph and BFS from any node with degree 1. 
*/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> restoreArray(vector<vector<int>> &adjacentPairs){
        map<int, vector<int>> adj;
        map<int, int> degree;

        for (vector<int> &v: adjacentPairs){
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
            degree[v[0]]++; degree[v[1]]++;
        }

        int st = -1;
        for (auto &[node, deg]: degree){
            if (deg == 1){
                st = node; break;
            }
        }

        queue<int> q;
        map<int, bool> vis;
        q.push(st); vis[st] = true;
        vector<int> ans;
        while (!q.empty()){
            int node = q.front(); q.pop();
            ans.push_back(node);
            for (int &u: adj[node]){
                if (vis[u]) continue;
                q.push(u); vis[u] = true;
            }
        }

        return ans;
    }
};

int main(){
    Solution solver;
    vector<vector<int>> adjacents{};
    vector<int> ans = solver.restoreArray(adjacents);
    exit(EXIT_SUCCESS);
}

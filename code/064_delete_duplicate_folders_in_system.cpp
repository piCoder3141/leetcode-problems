/* 7th January, 2024
 * Problem: Delete Duplicate Folders in a System( https://leetcode.com/problems/delete-duplicate-folders-in-system )
 * Difficulty: Hard
 * Solution: Build the tree. For every node, create a string from its subtree, which will serve as a hash for the node.
 *           Mark the nodes with the same hash and remove them.
*/

#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:
        vector<vector<pair<string, int>>> adj;
        vector<string> nodeToString, nodeHash;
        vector<bool> marked;
        map<string, vector<int>> hashNode;;
        vector<vector<string>> ans;

        string dfs_to_hash(int u){
            string hash = "";
            for (pair<string, int> &p: adj[u]){
                hash += "#";
                hash += dfs_to_hash(p.second);
            }

            if (hash != ""){
                if (hashNode.find(hash) == hashNode.end()) hashNode[hash] = vector<int>();
                hashNode[hash].push_back(u);
                nodeHash[u] = hash;
                hash += "!";
            }
            hash += nodeToString[u];
            return hash;
        }

        void dfs_to_ans(int u, vector<string> &path){
            if (u > 0){
                ans.push_back(path);
            }
            for (pair<string, int> &p: adj[u]){
                if (marked[p.second]) continue;
                path.push_back(p.first);
                dfs_to_ans(p.second, path);
                path.pop_back();
            }
        }


        vector<vector<string>> deleteDuplicateFolder(vector<vector<string>> &paths){
            int n = paths.size() + 1, allocatedNodes = 1;

            adj.assign(n, vector<pair<string, int>>());
            nodeToString.assign(n, "");
            marked.assign(n, false);
            nodeHash.assign(n, "");
            nodeToString[0] = "/";

            sort(paths.begin(), paths.end());

            for (auto &path: paths){
                int prevNode = 0;
                for (string &strNode: path){
                    if ((adj[prevNode].empty()) || (adj[prevNode].back().first != strNode)){
                        adj[prevNode].push_back({strNode, allocatedNodes});
                        nodeToString[allocatedNodes] = strNode;
                        allocatedNodes++;
                    }
                    prevNode = adj[prevNode].back().second;
                }
            }

            dfs_to_hash(0);

            for (auto const &[key, value]: hashNode){
                if (value.size() == 1) continue;
                for (const int &node: value) marked[node] = true;
            }

            vector<string> path;
            dfs_to_ans(0, path);
            return ans;
        }
};

int main(){
    exit(EXIT_SUCCESS);
}

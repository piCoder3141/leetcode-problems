/* 11th November, 2023.
 * Problem: Design Graph with Shortest Path Calculator ( https://leetcode.com/problems/restore-the-array-from-adjacent-pairs ) 
 * Difficulty: Hard
 * Solution: Dijkstra at each step.
*/

#include<bits/stdc++.h>

using namespace std;

class Graph {
public:
    vector<vector<pair<int, int>>> adj;
    const int INF = 1e9;
    int n;
    Graph(int n, vector<vector<int>> &edges){
        this->n = n;
        adj.assign(n, vector<pair<int, int>>());
        for (vector<int> &e: edges){
            adj[e[0]].push_back({e[1], e[2]});
        }
    }

    void addEdge(vector<int> e){
        adj[e[0]].push_back({e[1], e[2]});
    }

    int shortestPath(int s, int t){
        vector<int> d(n, INF);
        d[s] = 0;

        set<pair<int, int>> q;
        q.insert({0, s});
        while(!q.empty()){
            int from = q.begin()->second;
            q.erase(q.begin());

            for (pair<int, int> &edge: adj[from]){
                int to = edge.first, len = edge.second;
                if (d[to] > d[from] + len){
                    q.erase({d[to], to});
                    d[to] = d[from] + len;
                    q.insert({d[to], to});
                }
            }
        }

        return (d[t] == INF) ? -1: d[t];
    }
};

int main(){
    exit(EXIT_SUCCESS);
}

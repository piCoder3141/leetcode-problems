/* 18th October, 2023
 * Problem: Parallel Courses III ( https://leetcode.com/problems/parallel-courses-iii )
 * Difficulty: Hard
 * Solution: Topological BFS with dynamic programming. The minimum time required for a course is the minimum amount
 *           time required for completing its pre-requisites plus the time required to complete the given course.
*/

#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:
        int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time){
            vector<vector<int>> adj(n);
            vector<int> inDegree(n), dp(n);
            for (vector<int>& e: relations){
                adj[e[0]-1].push_back(e[1]-1);
                inDegree[e[1]-1]++;
            }

            queue<int> q;
            for (int i = 0; i < n; i++){
                dp[i] = time[i];
                if (inDegree[i] == 0) q.push(i);
            }

            int ans = 0;
            while (!q.empty()){
                int u = q.front(); q.pop();
                ans = max(ans, dp[u]);
                for (int& v: adj[u]){
                    dp[v] = max(dp[v], dp[u] + time[v]);
                    inDegree[v]--;
                    if (inDegree[v] == 0) q.push(v);
                }
            }

            return ans;
        }
};

int main(){
    Solution solver;
    vector<vector<int>> relations{{1, 3}, {2, 3}};
    vector<int> time{3, 2, 5};
    int n = 3;
    cout << solver.minimumTime(n, relations, time) << '\n';
    exit(EXIT_SUCCESS);
}

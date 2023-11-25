/* 13th November, 2023.
 * Problem: Sort Vowels in a String ( https://leetcode.com/problems/sort-vowels-in-a-string ) 
 * Difficulty: Hard
 * Solution: 
*/

#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:
        int numBusesToDestination(vector<vector<int>> &routes, int source, int target){
            if (source == target) return 0;
            int R = routes.size();
            const int MX = 1e6;
            vector<vector<int>> stop_routes(MX, vector<int>());
            
            int idx = 0;
            for (vector<int>& route: routes){
                for (int &stop: route){
                    stop_routes[stop].push_back(idx);
                }
                idx++;
            }

            vector<set<int>> adj(R, vector<int>());
            for (int i = 0; i < R; i++){
                for (int &stop: routes[i]){
                    for (int &route_num: stop_routes[stop]){
                        if (route_num == i) continue;
                        adj[i].insert(route_num);
                    }
                }
            }

            const int INF = 1e9;
            queue<int> q;
            vector<int> d(R, INF);
            for (int &route_num: stop_routes[source]){
                q.push(route_num);
                d[route_num] = 0;
            }

            while(!q.empty()){
                int route = q.front(); q.pop();
                for (int &nxt: adj[route]){
                    if (d[nxt] < INF) continue;
                    d[nxt] = d[route] + 1;
                    q.push(nxt);
                }
            }

            int ans = INF;
            for (int &route_num: stop_routes[target]) ans = min(ans, d[route_num]);

            return (ans == INF) ? -1 : ans+1;
        }
};

int main(){
    exit(EXIT_SUCCESS);
}

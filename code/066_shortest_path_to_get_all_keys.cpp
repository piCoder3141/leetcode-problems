/* 8th January, 2024
 * Problem: Shortest Path to get All Keys ( https://leetcode.com/problems/shortest-path-to-get-all-keys )
 * Difficulty: Hard
 * Solution: Generate all permuations of the keys, for each permuatation, trace the path and count number of steps.
*/

#include<bits/stdc++.h>

using namespace std;

class Solution{
    private:
        int m, n;
        bool isInside(int x, int y){
            return (x >= 0) && (y >= 0) && (x < m) && (y < n);
        }
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, -1, 0, 1};

    public:
        int solve(vector<string> &grid, int si, int sj, vector<char> &keys){
            int steps = 0;
            set<char> unlocked;
            for (const char &key: keys){
                bool found = false;
                queue<pair<int, int>> q;
                vector<vector<bool>> vis(m, vector<bool>(n));
                
                q.push({si, sj});
                vis[si][sj] = true;
                
                while (!q.empty()){
                    int sz = q.size();
                    for (int itr = 0; itr < sz; itr++){
                        int x = q.front().first, y = q.front().second;
                        if (grid[x][y] == key){
                            found = true;
                            si = x; sj = y;
                            break;
                        }
                        q.pop();
                        for (int d = 0; d < 4; d++){
                            int nx = x + dx[d], ny = y + dy[d];
                            if ((!isInside(nx, ny)) || (vis[nx][ny]) || (grid[nx][ny] == '#')) continue;
                            if ((grid[nx][ny] >= 65) && (grid[nx][ny] <= 70)){
                                if (unlocked.find(grid[nx][ny]) == unlocked.end()) continue;
                            }

                            vis[nx][ny] = true;
                            q.push({nx, ny});
                        }
                    }
                    if (found) break;
                    steps++;
                }

                if (!found) return INT_MAX;
                unlocked.insert(key-32);
            }

            return steps;
        }

        int shortestPathAllKeys(vector<string> &grid){
            vector<char> keys;
            m = grid.size(), n = grid[0].size();
            int si, sj;

            for (int i = 0; i < m; i++){
                for (int j = 0; j < n; j++){
                    if ((grid[i][j] >= 97) && (grid[i][j] <= 102)) keys.push_back(grid[i][j]);
                    if (grid[i][j] == '@') si = i, sj = j;
                }
            }
            sort(keys.begin(), keys.end());
            int ans = INT_MAX;

            do{
                ans = min(ans, solve(grid, si, sj, keys));
            } while (next_permutation(keys.begin(), keys.end()));

            return (ans == INT_MAX) ? -1: ans;
        }
};

int main(){
    exit(EXIT_SUCCESS);
}

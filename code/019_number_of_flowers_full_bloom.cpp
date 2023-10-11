/* 11th October, 2023
 * Problem: Number of Flowers in Full Bloom ( https://leetcode.com/problems/number-of-flowers-in-full-bloom )
 * Difficulty: Hard
 * Solution: Treat the blooming start and end time as events. At the start event, one flower is added to the set and
 *           and at the end event, one flower is deleted from the set. For each person, find the last event and return
 *           the number of flowers in the set after that event. 
*/

#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:
        vector<int> fullBloomFlowers(vector<vector<int>> &flowers, vector<int> &people){
            int n = people.size();
            vector<int> ans(n);

            vector<pair<int, int>> events;
            for (vector<int> &flower: flowers){
                events.push_back({flower[0], 0});
                events.push_back({flower[1]+1, 1});
            }
            sort(events.begin(), events.end());
            int m = events.size();
            
            vector<int> bloomed_flowers(m);
            bloomed_flowers[0] = 1;
            for (int i = 1; i < m; i++){
                if (events[i].second == 0) bloomed_flowers[i] = bloomed_flowers[i-1] + 1;
                else bloomed_flowers[i] = bloomed_flowers[i-1] - 1;
            }

            for (int i = 0; i < n; i++){
                pair<int, int> tmp{people[i], 2};
                int last_idx = upper_bound(events.begin(), events.end(), tmp) - events.begin() - 1;
                ans[i] = (last_idx == -1) ? 0 : bloomed_flowers[last_idx];
            }

            return ans;
        }
};

int main(){
    Solution solver;
    vector<vector<int>> flowers{{19, 37}, {19, 38}, {19, 35}};
    vector<int> people{6, 7, 21, 1, 13, 37, 5, 37, 46, 43};
    vector<int> ans = solver.fullBloomFlowers(flowers, people);
    for (int &d: ans){
        cout << d << " ";
    }
    cout << "\n";
    exit(EXIT_SUCCESS);
}

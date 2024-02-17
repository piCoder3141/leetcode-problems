/* 17th February, 2024
 * Problem: Furthest Building You can Reach ( https://leetcode.com/problems/furthest-building-you-can-reach )
 * Difficulty: Medium
 * Solution: Maintain a min heap to store the largest L differences encountered yet.
*/

#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:
        int furthestBuilding(vector<int> &heights, int bricks, int ladders){
            int n = heights.size();
            priority_queue<int, vector<int>, greater<int>> heap;

            for(int i = 1; i < n; i++){
                if (heights[i] <= heights[i-1]) continue;
                int diff = heights[i] - heights[i-1];
                if (heap.size() < ladders){
                    heap.push(diff);
                    continue;
                }
                if ((ladders > 0) && (diff > heap.top())){
                    int top = heap.top(); heap.pop();
                    heap.push(diff);
                    diff = top;
                }

                bricks -= diff;
                if (bricks < 0) return i-1;
            }
            return n-1;
        }
};

int main(){
    exit(EXIT_SUCCESS);
}

/* 5th November, 2023.
 * Problem: Find the Winner of an Array Game ( https://leetcode.com/problems/find-the-winner-of-an-array-game ) 
 * Difficulty: Medium
 * Solution: For each element, count how many consecutive wins it can have. Return an element with more than `k`
 *           consecutive wins. Else, return the maximum element of the array.
*/

#include<bits/stdc++.h>

using namespace std;

class Soluton {
public:
    int getWinner(vector<int>& a, int k) {
        int n = a.size();
        int win_count = 0;
        int curr = a[0];
        for (int i = 1; i < n; i++){
            if (curr > a[i]) win_count++;
            else{
                curr = a[i]; win_count = 1;
            }
            if (win_count == k) break;
        }
        return curr;
    }
};

int main(){
    Solution solver;
    vector<int> arr{2, 1, 3, 5, 4, 6, 7};
    cout << solver.getWinner(arr, 2);
    exit(EXIT_SUCCESS);
}

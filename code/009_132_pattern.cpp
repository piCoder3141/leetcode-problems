/* 30th September, 2023
 * Problem: 132 Pattern ( https://leetcode.com/problems/132-pattern )
 * Difficulty: Medium
 * Solution: Maintain a stack where the top element represents 'nums[j]'. The last popped element represents 'nums[k]'.
 *           Iterate backwards, if the current number is less than the last popped element, return true.
 *           Else, pop from stack until current element is greater than the top of the stack. Push current element to
 *           stack.
*/

#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:
        bool find132pattern(vector<int> &nums){
            const int INF = 1e9 + 1;
            int nums_k = -INF;
            stack<int> st;

            int n = nums.size();
            for (int i = n-1; i >= 0; i--){
                if (nums[i] < nums_k) return true;
                while (!st.empty() && st.top() < nums[i]){
                    nums_k = st.top(); st.pop();
                }
                st.push(nums[i]);
            }

            return false;
        }
};

int main(){
    Solution solver;
    vector<int> nums{1, 2, 4, 6, 5, 3};
    cout << solver.find132pattern(nums) << "\n";
    exit(EXIT_SUCCESS);
}

/* 2nd November, 2023.
 * Problem: Build an Array with Stack Operations ( https://leetcode.com/problems/build-an-array-with-stack-operations ) 
 * Difficulty: Medium
 * Solution: *shrug*
*/

#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:
        vector<string> buildArray(vector<int> &target, int n){
            int last = 0;
            vector<string> ans;
            for (int &d: target){
                for (;last < d-1; last++){
                    ans.push_back("Push");
                    ans.push_back("Pop");
                }
                ans.push_back("Push");
                last++;
            }
            return ans;
        }
};

int main(){
    exit(EXIT_SUCCESS);
}

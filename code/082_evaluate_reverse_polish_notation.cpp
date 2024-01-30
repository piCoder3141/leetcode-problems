/* 30th January, 2024
 * Problem: Evaluate Reverse Polish Notation ( https://leetcode.com/problems/evaluate-reverse-polish-notation )
 * Difficulty: Medium
 * Solution: Standard stack problem.
*/

#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:
        int evalRPN(vector<string>& tokens){
            stack<int> st;
            
            for (string &token: tokens){
                if (token == "+"){
                    int x = st.top(); st.pop();
                    int y = st.top(); st.pop();
                    st.push(x+y);
                }
                else if (token == "-"){
                    int x = st.top(); st.pop();
                    int y = st.top(); st.pop();
                    st.push(y-x);
                }
                else if (token == "*"){
                    int x = st.top(); st.pop();
                    int y = st.top(); st.pop();
                    st.push(x*y);
                }
                else if (token == "/"){
                    int x = st.top(); st.pop();
                    int y = st.top(); st.pop();
                    st.push(y/x);
                }
                else st.push(stoi(token));
            }

            return st.top();
        }
};

int main(){
    exit(EXIT_SUCCESS);
}

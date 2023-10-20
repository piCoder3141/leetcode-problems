/* 20th October, 2023
 * Problem: Flatten Nested List Iterator ( https://leetcode.com/problems/flatten-nested-list-iterator )
 * Difficulty: Medium
 * Solution: Keep a stack where each element is a nestedList and a position of the current pointer in the list. 
*/

#include<bits/stdc++.h>

using namespace std;

/*
 * class NestedInteger{
 *     public:
 *         // Return true if this NestedInteger holds a single integer, rather than nested list.
 *         bool isInteger() const;
 *
 *         // Return the single integer that this NestedInteger holds, if it holds a single integer.
 *         // The result is undefined if this NestedInteger holds a list.
 *         int getInteger const;
 *
 *         // Return the nested list that this NestedInteger holds, if it holds a nested list.
 *         const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator{
    private:
        vector<NestedInteger> tmp, nxt;
        stack<pair<vector<NestedInteger>, int>> st;
    public:
        NestedIterator(vector<NestedInteger> &nestedList){
            st.push({nestedList, 0});
        }

        int next(){
            tmp = st.top().first;
            int pos = st.top().second;
            st.pop(); st.push({tmp, pos+1});
            return tmp[pos].getInteger();
        }

        bool hasNext(){
            while(!st.empty()){
                tmp = st.top().first;
                int pos = st.top().second;
                int sz = tmp.size();
                if (pos == sz){
                    st.pop();
                }
                else{
                    if (tmp[pos].isInteger()){
                        return true;
                    }
                    else{
                        nxt = tmp[pos].getList();
                        st.pop(); st.push({tmp, pos+1});
                        st.push({nxt, 0});
                    }
                }
            }

            return false;
        }
};

int main(){
    exit(EXIT_SUCCESS);
}

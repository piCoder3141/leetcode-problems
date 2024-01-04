/* 4th January, 2024
 * Problem: Dinner Plate Stacks ( https://leetcode.com/problems/dinner-plate-stacks )
 * Difficulty: Hard
 * Solution: Maintain a heap of stacks that have been allocated but are empty. Use this heap to push to the leftmost
 *           stack.
*/

#include<bits/stdc++.h>

using namespace std;

class DinnerPlates{
    private:
        int stacksAllocated, capacity;
        priority_queue<int, vector<int>, greater<int>> left_heap;
        set<int, greater<int>> right_heap;

        bool isEmptyAtStack(int index){
            return (index >= this->stacksAllocated) || (dinnerPlates[index].size() == 0);
        }

        vector<vector<int>> dinnerPlates;

    public:
        DinnerPlates(int capacity){
            this->capacity = capacity;
            this->stacksAllocated = 0;
            this->dinnerPlates.clear();
        }

        void push(int val){
            if (this->left_heap.empty()){
                this->left_heap.push(stacksAllocated++);
                this->dinnerPlates.push_back(vector<int>());
            }

            int stack = this->left_heap.top();
            assert (this->dinnerPlates[stack].size() < this->capacity);
            dinnerPlates[stack].push_back(val);

            if (this->dinnerPlates[stack].size() == this->capacity) this->left_heap.pop();
            right_heap.insert(stack);
        }

        int pop(){
            if (this->right_heap.empty()) return -1;
            int stack = *(this->right_heap.begin());
            assert(this->dinnerPlates[stack].size() > 0);

            return this->popAtStack(stack);
        }

        int popAtStack(int stack){
            if (this->isEmptyAtStack(stack)) return -1;

            int ret = this->dinnerPlates[stack].back();
            if (this->dinnerPlates[stack].size() == 1) this->right_heap.erase(stack);
            if (this->dinnerPlates[stack].size() == this->capacity) this->left_heap.push(stack);
            this->dinnerPlates[stack].pop_back();

            return ret;

        }
};

int main(){
    exit(EXIT_SUCCESS);
}

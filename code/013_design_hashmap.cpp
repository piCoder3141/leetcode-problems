/* 4th October, 2023
 * Problem: Design Hashmap ( https://leetcode.com/problems/design-hashmap ) 
 * Difficulty: Easy
 * Solution: 
*/

#include<bits/stdc++.h>

using namespace std;

class MyHashMap{
    public:
        static const int MAX_SIZE = 1e5+1;
        int table[MAX_SIZE];
        MyHashMap(){
            memset(this->table, -1, sizeof(this->table));
        }

        void put(int key, int value){
            this->table[key] = value;
        }

        int get(int key){
            return this->table[key];
        }

        void remove(int key){
            this->table[key] = -1;
        }
};

int main(){
    MyHashMap mp;
    mp.put(1, 3);
    mp.put(4, 5);

    cout << mp.get(1) << '\n';
    cout << mp.get(4) << '\n';
    mp.remove(4);
    cout << mp.get(4) << '\n';
    exit(EXIT_SUCCESS);
}

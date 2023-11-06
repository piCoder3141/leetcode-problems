/* 6th November, 2023.
 * Problem: Seat Reservation Manager (https://leetcode.com/problems/seat-reservation-manager/) 
 * Difficulty: Medium
 * Solution: Create a set of of unreserved seats and add/remove seats from this set accordingly.
*/

#include<bits/stdc++.h>

using namespace std;

class SeatManager {
public:
    set<int> unreservedSeats;
    SeatManager(int n){
        for (int i = 1; i <= n; i++){
            unreservedSeats.insert(i);
        }
    }
    
    int reserve(){
        int ret = *unreservedSeats.begin();
        unreservedSeats.erase(unreservedSeats.begin());
        return ret;
    }

    void unreserve(int seatNumber){
        unreservedSeats.insert(seatNumber);
    }
};

int main(){
    Solution solver;
    vector<int> arr{2, 1, 3, 5, 4, 6, 7};
    cout << solver.getWinner(arr, 2);
    exit(EXIT_SUCCESS);
}

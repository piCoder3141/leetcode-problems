/* 12th October, 2023
 * Problem: Find in Mountain Array ( https://leetcode.com/problems/find-in-mountain-array )
 * Difficulty: Hard
 * Solution: Binary Search to find peak. Then two binary searches in either section.
*/

#include<bits/stdc++.h>

using namespace std;

/*
 * MountainArray's API interface.
 * class MountainArray{
 *     public:
 *         int get(int index);
 *         int length();
 * }
*/

class Solution{
    public:
        int search_in_sorted(int target, MountainArray &arr, int lo, int hi, bool inc){
            while (lo <= hi){
                int mid = lo + (hi - lo) / 2;
                int mid_val = arr.get(mid);
                if (mid_val == target) return mid;
                if (mid_val < target){
                    if (inc) lo = mid+1;
                    else hi = mid-1;
                }
                else{
                    if (inc) hi = mid-1;
                    else lo = mid+1;
                }
            }

            return -1;
        }

        int findInMountainArray(int target, MountainArray &arr){
            int n = arr.length();
            int lo = 1, hi = n-1, mid, peak = -1;
            int mid_val, next_val, prev_val;
            // Find peak.
            while(lo < hi){
                mid = lo + (hi - lo) / 2;
                mid_val = arr.get(mid);
                next_val = arr.get(mid+1);

                if (mid_val < next_val){
                    lo = mid+1;
                }
                else{
                    hi = mid;
                }
            }
            mid = lo;
            mid_val = arr.get(mid);
            if (mid_val == target) return mid;

            int lhs_search = search_in_sorted(target, arr, 0, peak-1, true);
            if (lhs_search != -1) return lhs_search;
            return search_in_sorted(target, arr, peak+1, n-1, false);
        }
};

int main(){
    exit(EXIT_SUCCESS);
}

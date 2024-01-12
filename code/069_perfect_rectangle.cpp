/* 9th January, 2024
 * Problem: Perect Rectangle ( https://leetcode.com/problems/perfect-rectangle )
 * Difficulty: Hard
 * Solution: Line sweep
*/

#include<bits/stdc++.h>

using namespace std;

#define Point pair<pair<int, int>, pair<int, int>>
#define x first.first
#define y first.second
#define ID second.first
#define LOC second.second
#define Line map<int, set<int>>

class Solution{
    public:
    void insert(Point p, Line &line){
        int id = p.ID;
        set<int> y_set = line[p.y];
        if (y_set.find(id) != y_set.end()){
            line[p.y].erase(id);
            if (line[p.y].empty()) line.erase(p.y);
        }
        else{
            line[p.y].insert(id);
        }
    }

    bool validate_lines(Line &low_line, Line &high_line, int lb, int ub, bool check_empty=false){
        if (check_empty){
            for (auto &[k, v]: low_line){
                if (!v.empty()) return false;
            }
            for (auto &[k, v]: high_line){
                if (!v.empty()) return false;
            }
        }
        else{
            if ((low_line[lb].size() != 1) || (high_line[ub].size() != 1)) return false;
            for (auto &[k, v]: low_line){
                if (k == lb) continue;
                if (v.size() != 1) return false;
                if (high_line[k].size() != 1) return false;
            }
            for (auto &[k, v]: high_line){
                if (k == ub) continue;
                if (v.size() != 1) return false;
                if (low_line[k].size() != 1) return false;
            }
        }
        return true;
    }

    bool isRectangleCover(vector<vector<int>> &rectangles){
        int n = rectangles.size();
        vector<Point> points;
        int lb = INT_MAX, ub = INT_MIN;
        for (int i = 0; i < n; i++){
            Point p1(make_pair(rectangles[i][0], rectangles[i][1]), make_pair(i, 0));
            Point p2(make_pair(rectangles[i][0], rectangles[i][3]), make_pair(i, 1));
            Point p3(make_pair(rectangles[i][2], rectangles[i][3]), make_pair(i, 1));
            Point p4(make_pair(rectangles[i][2], rectangles[i][1]), make_pair(i, 0));
            lb = min(lb, rectangles[i][1]);
            ub = max(ub, rectangles[i][3]);

            points.push_back(p1);
            points.push_back(p2);
            points.push_back(p3);
            points.push_back(p4);
        }

        sort(points.begin(), points.end());

        int N = n * 4;
        Line low_line, high_line;

        int line_x = points[0].x;
        insert(points[0], low_line);

        int i = 1;
        while((i < N) && (points[i].x == line_x)){
            if (points[i].LOC){
                insert(points[i], high_line);
            }
            else{
                insert(points[i], low_line);
            }
            i++;
        }

        bool check = validate_lines(low_line, high_line, lb, ub);
        if (!check) return false;

        while (i < N){
            line_x = points[i].x;
            insert(points[i], low_line);
            i++;
            while((i < N) && (points[i].x == line_x)){
                if (points[i].LOC){
                    insert(points[i], high_line);
                }
                else{
                    insert(points[i], low_line);
                }
                i++;
            }

            if (i < N) check = validate_lines(low_line, high_line, lb, ub);
            else check = validate_lines(low_line, high_line, lb, ub, true);
            if (!check) break;
        }

        return check;
    }
};

int main(){
    exit(EXIT_SUCCESS);
}

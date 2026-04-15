// Given the coordinates of four points in 2D space p1, p2, p3 and p4, return true if the four points construct a square.

// The coordinate of a point pi is represented as [xi, yi]. The input is not given in any order.

// A valid square has four equal sides with positive length and four equal angles (90-degree angles).


class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<vector<int>> points = {p1, p2, p3, p4};
        sort(points.begin(), points.end());
        
        int d1 = distance(points[0], points[1]);
        int d2 = distance(points[0], points[2]);
        int d3 = distance(points[0], points[3]);
        
        if (d1 == 0 || d2 == 0 || d3 == 0) return false;
        
        if (d1 == d2 && 2 * d1 == d3) {
            return distance(points[1], points[3]) == distance(points[2], points[3]) && distance(points[1], points[2]) == 2 * d1;
        }
        
        if (d1 == d3 && 2 * d1 == d2) {
            return distance(points[1], points[2]) == distance(points[3], points[2]) && distance(points[1], points[3]) == 2 * d1;
        }
        
        if (d2 == d3 && 2 * d2 == d1) {
            return distance(points[2], points[1]) == distance(points[3], points[1]) && distance(points[2], points[3]) == 2 * d2;
        }
        
        return false;
    }
    
    int distance(vector<int>& a, vector<int>& b) {
        return (a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]);
    }
};
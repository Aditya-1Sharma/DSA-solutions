// Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane, return the maximum number of points that lie on the same straight line.


class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int res = 1;
        for (int i=0; i<points.size(); ++i) {
            unordered_map<float, int> count;
            for (int j=i+1; j<points.size(); ++j) {
                float s = slope(points[i], points[j]);
                count[s] ++; 
                res = max(res, count[s] + 1);
            }
        }
        return res;
    }
private:
    float slope(vector<int>& p1, vector<int>& p2) {
        if ((p2[0] - p1[0]) == 0) 
            return INT_MAX; 
        return (float) (p2[1] - p1[1]) / (float) (p2[0] - p1[0]);
    }
};
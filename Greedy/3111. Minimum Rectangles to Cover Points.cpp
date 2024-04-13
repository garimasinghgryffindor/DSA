class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        sort(points.begin(), points.end());
        
        int res = 1;
        int last_x = points[0][0];
        for(auto point: points) {
            int x2 = point[0];
            if(x2 - last_x <= w) {
                // bdiya
            } else {
                res++;
                last_x = x2;
            }
        }
        return res;
    }
};

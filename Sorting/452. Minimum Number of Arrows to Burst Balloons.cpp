class Solution {
public:
    static bool compare(vector<int>&a,vector<int>&b) {
        return a[1] < b[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(),compare);
        
        int res = 1;
        
        int currEnd = points[0][1];
        for(auto x: points) {
            if(x[0] > currEnd) {
                res++;
                currEnd = x[1];
            }
        }
        
        return res;
    }
};

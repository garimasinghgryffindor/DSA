class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n = coordinates.size();
        if(n == 2) return true;

         int idx = 1;
        while (idx < n &&
               coordinates[idx][0] == coordinates[0][0] &&
               coordinates[idx][1] == coordinates[0][1]) {
            ++idx;
        }
        if (idx == n) return true; // all points are identical

        int X = coordinates[0][0];
        int Y = coordinates[0][1];
        int X1 = coordinates[1][0];
        int Y1 = coordinates[1][1];

        long long x0 = coordinates[0][0], y0 = coordinates[0][1];
        long long x1 = coordinates[idx][0], y1 = coordinates[idx][1];

        for (int i = 0; i < n; ++i) {
            long long xi = coordinates[i][0], yi = coordinates[i][1];
            if ((y1 - y0) * (xi - x0) != (yi - y0) * (x1 - x0))
                return false;
        }
        return true;
    }
};

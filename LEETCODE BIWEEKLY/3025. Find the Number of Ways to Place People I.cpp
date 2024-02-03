class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int maxi = 0;
        int n = points.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j || points[i][0] > points[j][0] || points[i][1] < points[j][1]) {
                    continue;
                }
                
                int k = 0;
                for (; k < n; k++) {
                    if (k == i || k == j) {
                        continue;
                    }
                    if (points[k][1] <= points[i][1] && points[k][1] >= points[j][1] && 
                        points[k][0] <= points[j][0] && points[k][0] >= points[i][0]) {
                        break;
                    }
                }

                if (k == n) {
                    maxi++;
                }
            }
        }

        return maxi;
    }
};

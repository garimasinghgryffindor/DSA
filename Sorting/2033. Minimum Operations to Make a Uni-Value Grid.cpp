class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n = grid.size();
        int m = grid[0].size();
        if(m == 1 && n == 1) return 0;

        vector<int>vec(m*n);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                vec[m*i+j] = grid[i][j];
            }
        }
        sort(vec.begin(), vec.end());
        for(int i = 1; i < m*n; i++) {
            if(vec[i-1]%x != vec[i]%x) return -1;
        }

        int res1 = 0, res2 = 0;
        int mx = vec[m*n/2-1];
        int mx2 = vec[m*n/2];
        for(int i = 0; i < m*n; i++) {
            res1 += (abs(mx-vec[i]))/x;
            res2 += (abs(mx2-vec[i]))/x;
        }

        return min(res1, res2);
    }
};

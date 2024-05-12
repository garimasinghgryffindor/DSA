class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> res(n-2, vector<int>(n-2, 0));
        
        for(int i = 0; i < n-2; i++) {
            for(int j = 0; j < n-2; j++) {
                res[i][j] = max({grid[i][j], grid[i+1][j], grid[i+2][j], grid[i][j+1], grid[i+1][j+1], grid[i+2][j+1], grid[i][j+2], grid[i+1][j+2], grid[i+2][j+2]});
            }
        }
        
        return res;
    }
};

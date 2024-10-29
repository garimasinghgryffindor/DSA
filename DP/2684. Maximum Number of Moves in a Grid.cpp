class Solution {
public:
    vector<vector<int>>dp;
    int recur(vector<vector<int>>&grid, int r, int c, int prev) {
        int n = grid.size(), m = grid[0].size();
        if(r >= n || c >= m || r < 0 || c < 0) return 0;
        if(grid[r][c] <= prev) return 0;
        if(dp[r][c] != -1) return dp[r][c];
        int curr = 1;
        curr = max(curr, 1 + recur(grid, r-1, c+1, grid[r][c]));
        curr = max(curr, 1 + recur(grid, r, c+1, grid[r][c]));
        curr = max(curr, 1 + recur(grid, r+1, c+1, grid[r][c]));
        
        return (dp[r][c] = curr);
    }
    
    int maxMoves(vector<vector<int>>& grid) {
        int res = 0;
        int r = grid.size(), c = grid[0].size();
        dp.resize(r, vector<int>(c, -1));
        
        for(int i = 0; i < r; i++) {
            res = max(res, recur(grid, i, 0, -1));
        }
        
        return res-1;
    }
};

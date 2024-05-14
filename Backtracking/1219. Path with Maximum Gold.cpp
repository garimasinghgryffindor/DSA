class Solution {
public:
    int recur(vector<vector<int>>&grid, int r, int c) {
        if(r >= grid.size() || r < 0 || c < 0 || c >= grid[0].size()) return 0;
        
        if(grid[r][c] == 0) return 0;
        int ans = grid[r][c];
        grid[r][c] = 0;
        int temp = 0;
        temp = max(temp, recur(grid, r+1, c));
        temp = max(temp, recur(grid, r, c+1));
        temp = max(temp, recur(grid, r-1, c));
        temp = max(temp, recur(grid, r, c-1));
        grid[r][c] = ans;
        return ans + temp;
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        int res = 0, r = grid.size(), c = grid[0].size();
        
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(grid[i][j] != 0) {
                    res = max(res, recur(grid, i, j));
                }
            }
        }
        return res;
    }
};

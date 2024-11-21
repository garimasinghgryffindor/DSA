class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        int grid[m][n];
        memset(grid, 0, sizeof(grid));
        int res = 0;
        
        for(auto x: guards) {
            grid[x[0]][x[1]] = 2;
        }
        
        for(auto x: walls) {
            grid[x[0]][x[1]] = 2;
        }
        
        vector<int>dirs = {-1, 0, 1, 0, -1};
        
        for(auto g: guards) {
            
            for(int i = 0; i < 4; i++) {
                int new_x = dirs[i];
                int new_y = dirs[i+1];
                int x = g[0], y = g[1];
                
                while(new_x+x >= 0 && new_y+y >= 0 && new_x+x < m && new_y+y < n && grid[new_x+x][new_y+y] < 2) {
                    x = new_x+x;
                    y = new_y+y;
                    grid[x][y] = 1;
                }
            }
        }
        
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) res++;
            }
        }
        return res;
    }
};

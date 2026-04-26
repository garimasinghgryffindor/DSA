class Solution {
public:
    bool dfs(vector<vector<char>>&grid, vector<vector<bool>>&visited, int r, int c, int pr, int pc) {
        int n = grid.size();
        int m = grid[0].size();
        if(r < 0 || c < 0 || r >= n || c >= m) return false;

        if(visited[r][c]) return true;
        visited[r][c] = true;
        // let's start to visit em one by one
        // right
        if(!(c+1 == pc && r == pr) && c+1 < m && grid[r][c+1] == grid[r][c]) {
            if(dfs(grid, visited, r, c+1, r, c)) return true;
        }

        // left
        if(!(c-1 == pc && r == pr) && c-1 >= 0 && grid[r][c-1] == grid[r][c]) {
            if(dfs(grid, visited, r, c-1, r, c)) return true;
        }

        // up
        if(!(c == pc && r-1 == pr) && r-1 >= 0 && grid[r-1][c] == grid[r][c]) {
            if(dfs(grid, visited, r-1, c, r, c)) return true;
        }

        // down
        if(!(c == pc && r+1 == pr) && r+1 < n && grid[r+1][c] == grid[r][c]) {
            if(dfs(grid, visited, r+1, c, r, c)) return true;
        }

        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>>visited(n, vector<bool>(m, false));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(visited[i][j]) {
                    continue;
                }
                bool isCycle = dfs(grid, visited, i, j, -1, -1);
                if(isCycle) return true;
            }   
        }

        return false;
    }
};

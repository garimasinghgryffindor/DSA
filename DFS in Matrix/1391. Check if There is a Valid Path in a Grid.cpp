class Solution {
public:
    bool dfs(vector<vector<int>>&grid, vector<vector<bool>>&visited, int r, int c, int dir) {
        int n = grid.size();
        int m = grid[0].size();
        if(r < 0 || c < 0 || r >= n || c >= m) return false;
        
        
        if(visited[r][c]) return false;
        
        visited[r][c] = true;
        // visit start moving
        if(grid[r][c] == 1) {
            if(dir == 0) {
                // coming from left
                if(r == n-1 && c == m-1) return true;
                if(dfs(grid, visited, r, c+1, 0)) return true;
            } else if(dir == 1) {
                // coming from right
                if(dfs(grid, visited, r, c-1, 1)) return true;
            } else if(dir == 2) {
                // coming from top
            } else {
                // coming from bottom
            }
        } else if(grid[r][c] == 2) {
            if(dir == 0) {
                // coming from left
            } else if(dir == 1) {
                // coming from right
            } else if(dir == 2) {
                // coming from top
                if(r == n-1 && c == m-1) return true;
                if(dfs(grid, visited, r+1, c, 2)) return true;
            } else {
                // coming from bottom
                if(dfs(grid, visited, r-1, c, 3)) return true;
            }
        } else if(grid[r][c] == 3) {
            if(dir == 0) {
                // coming from left
                if(r == n-1 && c == m-1) return true;
                if(dfs(grid, visited, r+1, c, 2)) return true;
            } else if(dir == 1) {
                // coming from right
            } else if(dir == 2) {
                // coming from top
            } else {
                // coming from bottom
                if(dfs(grid, visited, r, c-1, 1)) return true;
            }
        } else if(grid[r][c] == 4) {
            if(dir == 0) {
                // coming from left
            } else if(dir == 1) {
                // coming from right
                if(dfs(grid, visited, r+1, c, 2)) return true;
            } else if(dir == 2) {
                // coming from top
            } else {
                // coming from bottom
                if(dfs(grid, visited, r, c+1, 0)) return true;
            }
        } else if(grid[r][c] == 5) {
            if(dir == 0) {
                // coming from left
                if(r == n-1 && c == m-1) return true;
                if(dfs(grid, visited, r-1, c, 3)) return true;
            } else if(dir == 1) {
                // coming from right
            } else if(dir == 2) {
                // coming from top
                if(r == n-1 && c == m-1) return true;
                if(dfs(grid, visited, r, c-1, 1)) return true;
            } else {
                // coming from bottom
            }
        } else {
            if(dir == 0) {
                // coming from left
            } else if(dir == 1) {
                // coming from right
                if(dfs(grid, visited, r-1, c, 3)) return true;
            } else if(dir == 2) {
                // coming from top
                if(r == n-1 && c == m-1) return true;
                if(dfs(grid, visited, r, c+1, 0)) return true;
            } else {
                // coming from bottom
            }
        }

        visited[r][c] = false;
        return false;
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>>visited(n, vector<bool>(m, false));

        if(grid[0][0] == 1) {
            return dfs(grid, visited, 0, 0, 0);
        } else if(grid[0][0] == 2) {
            return dfs(grid, visited, 0, 0, 2);
        } else if(grid[0][0] == 3) {
            return dfs(grid, visited, 0, 0, 0);
        } else if(grid[0][0] == 4) {
            if(dfs(grid, visited, 0, 0, 1)) return true;
            return dfs(grid, visited, 0, 0, 3);
        } else if(grid[0][0] == 5) {
            return false;
        } else {
            return dfs(grid, visited, 0, 0, 2);
        }
        return false;
    }
};

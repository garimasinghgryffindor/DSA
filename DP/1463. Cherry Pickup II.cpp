class Solution {
public:
    int recur(vector<vector<int>>& grid, int row, int c1, int c2) {
        if(row == grid.size()) return 0;
        if(c1 < 0 || c2 < 0 || c1 >= grid[0].size() || c2 >= grid[0].size()) return 0;
        
        int temp = grid[row][c1] + grid[row][c2];
        if(c1 == c2) {
            temp = grid[row][c1];
        }
        
        int res1 = recur(grid, row+1, c1, c2);
        int res2 = recur(grid, row+1, c1+1, c2);
        int res3 = recur(grid, row+1, c1-1, c2);
        int res4 = recur(grid, row+1, c1, c2+1);
        int res5 = recur(grid, row+1, c1, c2-1);
        int res6 = recur(grid, row+1, c1+1, c2+1);
        int res7 = recur(grid, row+1, c1-1, c2+1);
        int res8 = recur(grid, row+1, c1+1, c2-1);
        int res9 = recur(grid, row+1, c1-1, c2-1);
        
        return temp + max({res1, res2, res3, res4, res5, res6, res7, res8, res9});
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        
        int row = 0, c1 = 0, c2 = c-1;
        return recur(grid, row, c1, c2);
    }
};



// MEMOIZATION
class Solution {
public:
    int mem[70][70][70];
    int recur(vector<vector<int>>& grid, int row, int c1, int c2) {
        if(row == grid.size()) return 0;
        if(c1 < 0 || c2 < 0 || c1 >= grid[0].size() || c2 >= grid[0].size()) return 0;
        
        if(mem[row][c1][c2] != -1) return mem[row][c1][c2];
        
        int temp = grid[row][c1] + grid[row][c2];
        if(c1 == c2) {
            temp = grid[row][c1];
        }
        
        int res1 = recur(grid, row+1, c1, c2);
        int res2 = recur(grid, row+1, c1+1, c2);
        int res3 = recur(grid, row+1, c1-1, c2);
        int res4 = recur(grid, row+1, c1, c2+1);
        int res5 = recur(grid, row+1, c1, c2-1);
        int res6 = recur(grid, row+1, c1+1, c2+1);
        int res7 = recur(grid, row+1, c1-1, c2+1);
        int res8 = recur(grid, row+1, c1+1, c2-1);
        int res9 = recur(grid, row+1, c1-1, c2-1);
        
        return mem[row][c1][c2] = temp + max({res1, res2, res3, res4, res5, res6, res7, res8, res9});
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        memset(mem, -1, sizeof(mem));
        
        int row = 0, c1 = 0, c2 = c-1;
        return recur(grid, row, c1, c2);
    }
};



// TABULATION
class Solution {
public:
    int mem[71][72][72];
    
    int cherryPickup(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        int row = 0, c1 = 0, c2 = c-1;
        
        for(int i = r-1; i >= 0; i--) {
            for(int j = 0; j < c; j++) {
                for(int k = 0; k < c; k++) {
                    int temp = grid[i][j] + grid[i][k];
                    if(j == k) {
                        temp = grid[i][j];
                    }

                    int res1 = mem[i+1][j+1][k +1];
                    int res2 = mem[i+1][j+1 +1][k +1];
                    int res3 = mem[i+1][j-1 +1][k +1];
                    int res4 = mem[i+1][j +1][k+1 +1];
                    int res5 = mem[i+1][j +1][k-1 +1];
                    int res6 = mem[i+1][j+1 +1][k+1 +1];
                    int res7 = mem[i+1][j-1 +1][k+1 +1];
                    int res8 = mem[i+1][j+1 +1][k-1 +1];
                    int res9 = mem[i+1][j-1 +1][k-1 +1];

                    mem[i][j +1][k +1] = temp + max({res1, res2, res3, res4, res5, res6, res7, res8, res9});
                }
            }
        }
        
        
        return mem[row][c1 +1][c2 +1];
    }
};


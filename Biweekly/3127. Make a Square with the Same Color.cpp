class Solution {
public:
    bool canMakeSquare(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        for(int i = 0; i < n-1; i++) {
            for(int j = 0; j < m-1; j++) {
                int sum = 0;
                if(grid[i][j] == 'B') sum++;
                if(grid[i+1][j] == 'B') sum++;
                if(grid[i][j+1] == 'B') sum++;
                if(grid[i+1][j+1] == 'B') sum++;
                if(sum == 0 || sum == 1 || sum == 4 || sum == 3) return true;
            }
        }
        
        return false;
    }
};

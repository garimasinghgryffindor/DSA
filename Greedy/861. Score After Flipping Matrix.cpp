class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int res = 0, r = grid.size(), c = grid[0].size();
        for(int i = 0; i < r; i++) { 
            if(grid[i][0] == 0) {
                // then toggle
                for(int j = 0; j < c; j++) {
                    grid[i][j] = 1 - grid[i][j];
                }
            } else {
                // leave it as it is
            }
        }
        
        for(int i = 0; i < c; i++) {
            int temp = 0;
            for(int j = 0; j < r; j++) {
                temp += grid[j][i];
            }
            if(temp < r - temp) {
                // then toggle the bits
                for(int j = 0; j < r; j++) {
                    grid[j][i] = 1 - grid[j][i];
                }
            } else {
                // leave it as it is
            }
        }
        
        for(int i = 0; i < r; i++) {
            int temp = 0;
            for(int j = 0; j < c; j++) {
                temp = temp*2 + grid[i][j];
            }
            res += temp;
        }
        
        return res;
    }
};

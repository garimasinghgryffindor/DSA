class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int res = INT_MAX;
        
        vector<vector<int>>dp(n, vector<int>(n, INT_MAX));
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0) {
                    dp[i][j] = grid[i][j];
                } else {
                    for(int k = 0; k < n; k++) {
                        if(k!=j) {
                            dp[i][j] = min(dp[i][j], grid[i][j] + dp[i-1][k]);
                        }
                    }
                }
            }
        }
        
        for(int i = 0; i < n; i++) {
            res = min(res, dp[n-1][i]);
        }
        
        return res;
    }
};

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        if(grid.size()==0) 
            return -1;
        
        int res = -1, n=grid.size(), m=grid[0].size();
        if (grid.empty() || grid[0].empty())
        {
            return res;
        }
        queue<pair<int,int>> q;
        vector<vector<int>> dp(n, vector<int>(m,INT_MAX));
        for(int i=0 ; i<n ; i++) {
            for(int j=0 ; j<m ; j++) {
                if(grid[i][j] == 1) {
                    q.push({i,j});
                    dp[i][j] = 0;
                }
            }
        }
        
        if(q.empty())
            return -1;
        
        int X[] = {0, 1 , 0, -1};
        int Y[] = {1, 0 , -1, 0};
        
        while(!q.empty()) {
            int posx = q.front().first;
            int posy = q.front().second;
            
            q.pop();
            
            for(int i=0 ; i<4 ; i++) {
                int x = posx + X[i];
                int y = posy + Y[i];
                
                if(x>=0 && x<n && y>=0 && y<m) {
                    if(dp[x][y] == INT_MAX) {
                        q.push({x,y});
                    }
                    dp[x][y] = min(dp[x][y] , dp[posx][posy]+1);
                }
            }
        }
        
        for(int i=0 ; i<n ; i++) {
            for(int j=0 ; j<m ; j++) {
                if(grid[i][j]==0)
                    res = max(res,dp[i][j]);
            }
        }
        
        return res;
    }
};

// using BFS

// LEETCODE 1162

// Given an n x n grid containing only values 0 and 1, where 0 represents water and 1 represents land, find a water cell such that its distance to the nearest land cell is maximized, and return the distance. If no land or water exists in the grid, return -1.

// The distance used in this problem is the Manhattan distance: the distance between two cells (x0, y0) and (x1, y1) is |x0 - x1| + |y0 - y1|.







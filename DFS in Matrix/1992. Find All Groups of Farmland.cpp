class Solution {
public:
    void dfs(vector<vector<int>>&land, vector<vector<bool>>&vis, vector<vector<int>>&res, int r, int c, int t, int l) {
        if(vis[r][c]) return;
        
        vis[r][c] = true;
        if(t == -1 && l == -1) {
            t = r;
            l = c;
        }
        
        if(r == land.size()-1 && c == land[0].size()-1) {
            res.push_back({t, l, r, c});    return;
        }
        
        if(r == land.size()-1) {
            if(!land[r][c+1]) {
                res.push_back({t, l, r, c});
            } else {
                dfs(land, vis, res, r, c+1, t, l);
            }
            return;
        }
        
        if(c == land[0].size()-1) {
            if(!land[r+1][c]) {
                res.push_back({t, l, r, c});
            } else {
                dfs(land, vis, res, r+1, c, t, l);
            }
            return;
        }
        
        if(!land[r][c+1] && !land[r+1][c]) {
            res.push_back({t, l, r, c});    return;
        }
        
        if(land[r][c+1]) {
            dfs(land, vis, res, r, c+1, t, l);
        }
        if(land[r+1][c]) {
            dfs(land, vis, res, r+1, c, t, l);
        }
    }
    
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> res;
        int n = land.size(), m = land[0].size();
        vector<vector<bool>>vis(n, vector<bool>(m, false));
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!vis[i][j] && land[i][j]) {
                    dfs(land, vis, res, i, j, -1, -1);
                }
            }
        }
        
        return res;
    }
};

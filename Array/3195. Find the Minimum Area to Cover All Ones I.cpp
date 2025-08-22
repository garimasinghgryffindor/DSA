class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int l = col-1;
        int r = 0;
        int t = row-1;
        int b = 0;
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(grid[i][j] == 1) {
                    l = min(l, j);
                    r = max(r, j);
                    t = min(t, i);
                    b = max(b, i);
                }
            }
        }
        // cout<<"l:"<<l<<"   r:"<<r<<"   t:"<<t<<"   b:"<<b<<endl;
        return (b-t+1)*(r-l+1);
    }
};

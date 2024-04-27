class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        long long res = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<long long> row(n, 0);
        vector<long long> col(m, 0);
        
        for(int i = 0; i < n; i++) {
            int sum = 0;
            for(int j = 0; j < m; j++) {
                sum += grid[i][j];
            }
            row[i] = sum;
        }
        
        for(int i = 0; i < m; i++) {
            int sum = 0;
            for(int j = 0; j < n; j++) {
                sum += grid[j][i];
            }
            col[i] = sum;
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 0) continue;
                if(row[i] == 0 || col[j] == 0) continue;
                long long a = row[i]-1;
                long long b = col[j]-1;
                // a = a*(a-1)/2;
                // b = b*(b-1)/2;
                // cout<<a*b<<"    ";
                res += a*b;
            }
        }
        
        return res;
    }
};

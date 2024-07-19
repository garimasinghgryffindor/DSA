class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int>res;
        int r = matrix.size(), c = matrix[0].size();
        vector<int>rows(r, 0);
        for(int i = 0; i < r; i++) {
            // this is one row
            int mn = 0;
            for(int j = 1; j < c; j++) {
                if(matrix[i][j] < matrix[i][mn]) {
                    mn = j;
                }
            }
            rows[i] = mn;
        }
        
        vector<int>cols(c, 0);
        for(int i = 0; i < c; i++) {
            // this is one col
            int mx = 0;
            for(int j = 1; j < r; j++) {
                if(matrix[j][i] > matrix[mx][i]) {
                    mx = j;
                }
            }
            cols[i] = mx;
        }
        
        for(int i = 0; i < r; i++) {
            int r_ = i;
            int c_ = rows[i];
            if(cols[c_] == r_) {
                res.push_back(matrix[r_][c_]);
            }
        }
        
        return res;
    }
};

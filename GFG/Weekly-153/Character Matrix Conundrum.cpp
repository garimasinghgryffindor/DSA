
class Solution {
  public:
    bool matrixConundrum(int n, int m, vector<string> &mat) {
        if(m < 4) return false;
        
        bool p = false, l = false, a = false, y = false;
        // vector<vector<bool>> vis(m, vector<bool>(4, false));
        for(int i = 0; i < m; i++) {
            bool p_ = false, l_ = false, a_ = false, y_ = false;
            for(int j = 0; j < n; j++) {
                if(mat[j][i] == 'p') {
                    p_ = true;
                } else if(mat[j][i] == 'l' && p) {
                    l_ = true;
                } else if(mat[j][i] == 'a' && l) {
                    a_ = true;
                } else if(mat[j][i] == 'y' && a) {
                    y_ = true;
                }
                
                if(y_) return true;
            }
            p = p || p_;
            l = l || l_;
            a = a || a_;
            y = y || y_;
        }
        return false;
    }
};

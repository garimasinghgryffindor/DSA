// class Solution {
// public:
//     int countSquares(vector<vector<int>>& matrix) {
//         int res = 0;
//         // brute force
//         int r = matrix.size(), c = matrix[0].size();
//         int mn = 1, mx = min(r, c);
//         vector<vector<int>> dp_r(r+1, vector<int>(c+1, 0));
//         vector<vector<int>> dp_c(r+1, vector<int>(c+1, 0));
//         for(int i = 1; i <= r; i++) {
//             for(int j = 1; j <= c; j++) {
//                 dp_r[i][j] = dp_r[i][j-1] + matrix[i-1][j-1]; 
        
//                 dp_c[i][j] = dp_c[i-1][j] + matrix[i-1][j-1];
//             }
//         }
        
//         for(int i = mn; i <= mx; i++) {
//             for(int j = 0; j <= r-i; j++) {
//                 for(int k = 0; k <= c-i; k++) {
//                     bool flag = true;
//                     for(int l = 0; l < i; l++) {
//                         // checking rows
//                         if(dp_r[j+1+l][k+i] - dp_r[j+1+l][k] == i) {
//                             // all good
//                         } else {
//                             flag = false;
//                             break;
//                         }
                        
//                         // checking cols
//                         if(dp_c[j+i][l+k+1] - dp_c[j][l+k+1] == i) {
//                             // all good
//                         } else {
//                             flag = false;
//                             break;
//                         }
//                     }
                    
//                     if(flag) {
//                         res++;
//                     }
//                 }
//             }
//         }
        
//         return res;
//     }
// };


class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int res = 0;
        // brute force
        int r = matrix.size(), c = matrix[0].size();
        vector<vector<int>> dp(r, vector<int>(c, 0));
        
        for(int i = 0; i < r; i++) {
            dp[i][0] = matrix[i][0];
            res += dp[i][0];
        }
        
        for(int i = 1; i < c; i++) {
            dp[0][i] = matrix[0][i];
            res += dp[0][i];
        }
        
        for(int i = 1; i < r; i++) {
            for(int j = 1; j < c; j++) {
                if(matrix[i][j] == 1) {
                    dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
                }
                
                res += dp[i][j];
            }
        }
        
        return res;
    }
};

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long res = 0;
        int x = 0, y = 0, n = matrix.size(), cnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] < 0) {
                    cnt++;
                }
                if(abs(matrix[i][j]) < abs(matrix[x][y])) {
                    x = i;
                    y = j;
                }
                res += (long long)abs(matrix[i][j]);
            }
        }

        if(cnt%2 == 0) {
            return res;
        }

        return res - 2*(abs(matrix[x][y]));
    }
};

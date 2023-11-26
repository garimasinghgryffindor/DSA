// You are given a 0-indexed m x n integer matrix mat and an integer k. You have to cyclically right shift odd indexed rows k times and 
// cyclically left shift even indexed rows k times.

// Return true if the initial and final matrix are exactly the same and false otherwise.


class Solution {
public:
    
    bool isSameMatrix(const vector<vector<int>>& mat1, const vector<vector<int>>& mat2) {
        int m = mat1.size();
        int n = mat1[0].size();

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat1[i][j] != mat2[i][j]) {
                    return false;
                }
            }
        }

        return true;
    }

    void cyclicShift(vector<int>& row, int k, bool rightShift) {
        int n = row.size();
        k = k % n;

        if (rightShift) {
            reverse(row.begin(), row.end());
            reverse(row.begin(), row.begin() + k);
            reverse(row.begin() + k, row.end());
        } else {
            reverse(row.begin(), row.begin() + k);
            reverse(row.begin() + k, row.end());
            reverse(row.begin(), row.end());
        }
    }
    
    bool areSimilar(vector<vector<int>>& mat, int k) {
               int m = mat.size();
                int n = mat[0].size();

                vector<vector<int>> initialMatrix = mat;

                for (int i = 0; i < m; ++i) {
                    if (i % 2 == 1) {
                        cyclicShift(mat[i], k, true); // Cyclically right shift odd indexed rows k times
                    } else {
                        cyclicShift(mat[i], k, false); // Cyclically left shift even indexed rows k times
                    }
                }

                return isSameMatrix(initialMatrix, mat);
    }
};

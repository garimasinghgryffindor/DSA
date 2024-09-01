class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int sz = original.size();
        if(sz != m*n) return {};
        vector<vector<int>>res(m, vector<int>(n, 0));
        int x = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                res[i][j] = original[x++];
            }
        }
        return res;
    }
};

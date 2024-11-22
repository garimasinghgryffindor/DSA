class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> mp;
        int res = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i = 0; i < n; i++) {
            string temp = "";
            for(int j = 0; j < m; j++) {
                temp.push_back('0'+matrix[i][j]);
            }
            mp[temp]++;
        }

        for(auto x: mp) {
            string temp = x.first;
            int cnt = x.second;
            string inv = temp;
            for(int i = 0; i < m; i++) {
                inv[i] = (1-(inv[i]-'0'))+'0';
            }
            if(mp.find(inv) != mp.end()) {
                res = max(res, mp[inv]+cnt);
            } else {
                res = max(res, cnt);
            }
        }

        return res;
    }
};

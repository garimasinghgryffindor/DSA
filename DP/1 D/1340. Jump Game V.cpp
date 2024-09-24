class Solution {
public:
    int recur(vector<int>&vec, int idx, int d, vector<int>&dp) {
        if(idx == vec.size() || idx < 0) return 0;
        
        if(dp[idx] != -1) return dp[idx];
        
        int res = 0;
        // going left d steps
        for(int i = 1; i <= d; i++) {
            if(idx-i >= 0 && vec[idx-i] < vec[idx])
                res = max(res, 1 + recur(vec, idx-i, d, dp));
            else break;
        }
        
        // going right d steps
        for(int i = 1; i <= d; i++) {
            if(idx+i < vec.size() && vec[idx+i] < vec[idx])
                res = max(res, 1 + recur(vec, idx+i, d, dp));
            else break;
        }
        
        res = max(res, 1);
        
        return dp[idx] = res;
    }
    
    int maxJumps(vector<int>& arr, int d) {
        int res = 0, n = arr.size();
        vector<int>dp(n, -1);
        for(int i = 0;  i < n; i++) {
            res = max(res, recur(arr, i, d, dp));
        }
        return res;
    }
};

// using LIS

// RECURSION
class Solution {
public:
    int recur(string &s, int &k, int idx, int prev) {
        int n = s.length();
        if(idx == n) return 0;
        
        int res = 0;
        if(prev == -1 || abs(s[idx]-prev) <= k) {
            res = 1 + recur(s, k, idx+1, s[idx]);
        }
        
        res = max(res, recur(s, k, idx+1, prev));
        
        return res;
    }
    int longestIdealString(string s, int k) {
        int res = recur(s, k, 0, -1);
        return res;
    }
};

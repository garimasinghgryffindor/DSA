// Recursion -> TLE

class Solution {
public:
    void recur(vector<int>&cookies, int&k, vector<int>bitMask, int idx, int & res,vector<int>&sum) {
        if(idx == cookies.size()) {
            
            int AND = 0;
            for(int i = 0; i < k ; i++) {
                if((AND & bitMask[i]) == 0) {
                    AND = AND | bitMask[i];
                } else return;
            }
            
            int shouldBeOr = (1 << idx) - 1;
            
            if(AND != shouldBeOr) return;
            
            int ans = 0;
            for(int i = 0; i < k; i++) {
                int sum_ = sum[bitMask[i]];
                ans = max(ans, sum_);
            }
            res = min(ans, res);
            return ;
        }
        
        for(int i = 0; i < k; i++) {
            // idx-th cookie can be given to any of the k children
            bitMask[i] = bitMask[i] | (1<<idx);
            recur(cookies, k, bitMask, idx+1, res, sum);
            bitMask[i] = bitMask[i] & (~(1<<idx));
        }
        
    }
    
    int distributeCookies(vector<int>& cookies, int k) {
        int n = cookies.size();
        
        vector<int>sum(1ll << n);
        for(int mask = 0;mask<(1ll << n); mask++){
            int total = 0;
            for(int i = 0;i<n;i++){
                if(mask & (1ll << i)){
                    total += cookies[i];
                }
            }
            sum[mask] = total;
        }
        
        vector<int>bitMask(k, 0);
        int res = INT_MAX;
        recur(cookies, k, bitMask, 0, res, sum);
        return res;
    }
};


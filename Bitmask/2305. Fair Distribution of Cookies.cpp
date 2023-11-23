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



// BITMASKING

class Solution {
public:
    int distributeCookies(vector<int>& cookies, int k) {
        int n = cookies.size();
        vector<vector<int>>dp(k + 1, vector<int>(1ll << n, INT_MAX));
        
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
        
        dp[0][0] = 0;
        
        
        for(int person = 1; person <= k; person++) {
            for(int mask = 0; mask < (1ll << n); mask++) {
                for(int submask = mask; submask > 0; submask = (submask-1)&mask) {
                    dp[person][mask] = min(dp[person][mask] , max(sum[submask], dp[person-1][submask^mask]));
                }
            }
        }
        
        return dp[k][(1ll << n)-1];
    }
};



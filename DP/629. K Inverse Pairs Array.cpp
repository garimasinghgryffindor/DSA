// RECURSION
class Solution {
public:
    int mod = 1e9 + 7;
    
    int recur(int n, int k) {
        if(k <= 0) {
            return k == 0;
        }
        if(n < 0) return 0;
        
        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans = (ans + recur(n-1, k-i))%mod;
        }
        return ans;
    }
    
    int kInversePairs(int n, int k) {
        return recur(n, k);
    }
};


// MEMOIZATION
class Solution {
public:
    int mod = 1e9 + 7;
    int dp[1001][1001];
    
    int recur(int n, int k) {
        if(k <= 0) {
            return k == 0;
        }
        if(n < 0) return 0;
        
        if(dp[n][k] != -1) return dp[n][k];
        
        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans = (ans + recur(n-1, k-i))%mod;
        }
        return dp[n][k] = ans;
    }
    
    int kInversePairs(int n, int k) {
        memset(dp, -1, sizeof(dp));
        return recur(n, k);
    }
};






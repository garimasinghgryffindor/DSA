class Solution {
public:
    int nthUglyNumber(int n) {
        if(n<=0) return false;
        if(n==1) return true;
        
        int d2 = 0 , d3 = 0 , d5 = 0;
        vector<int> dp(n);
        dp[0] = 1;
        for(int i=1 ; i<n ; i++){
            dp[i] = min(dp[d2]*2,min(dp[d3]*3 , dp[d5]*5));
            if(dp[i] == dp[d2]*2) d2++;
            if(dp[i] == dp[d3]*3) d3++;
            if(dp[i] == dp[d5]*5) d5++;
        }
        
        return dp[n-1];
    }
};

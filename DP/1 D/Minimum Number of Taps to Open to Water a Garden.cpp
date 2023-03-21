class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int>dp(n+1,n+2);
        dp[0] = 0;
        for(int i=0 ; i<=n ; ++i) {
            int lhs = max(0, i-ranges[i]+1);
            int rhs = min(n, i+ranges[i]);
            for(int j=lhs ; j<=rhs ; ++j) {
                dp[j] = min(dp[j], dp[max(0,i-ranges[i])]+1);
            }
        }
        
        return dp[n] < n+2 ? dp[n] : -1;
    }
};

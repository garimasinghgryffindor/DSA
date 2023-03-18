class Solution {
public:
    int knightDialer(int n) {
        int MOD = 1e9+7;
        vector<vector<long long int>> dp(n+1 , vector<long long int>(10,0));
        for(int i=0 ; i<10 ; i++) {
            dp[1][i] = 1;
        }
        
        vector<vector<int>> paths = {{4,6},{6,8},{7,9},{4,8},{0,3,9},{},{0,1,7},{2,6},{1,3},{2,4}};
        
        long long int res = 0;
        
        for(int i=2 ; i<=n ; i++) {
            for(int j=0 ; j<10 ; j++) {
                for(auto x: paths[j]) {
                    dp[i][j] += dp[i-1][x];
                }
                dp[i][j]%=MOD;
            }
        }
        
        for(int i=0 ; i<10 ; i++) {
            res += dp[n][i];
        }
        
        return res%MOD;
    }
};

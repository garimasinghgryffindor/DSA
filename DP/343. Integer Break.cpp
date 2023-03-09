class Solution {
public:
    int integerBreak(int n) {
        if (n <= 2)
            return 1;

        vector<int> dp(n+1, 0);
        dp[1] = 0;
        dp[2] = 1;
        
        for(int i=3 ; i<=n ; i++) {
            for (int j=1; j<i; j++) {
                dp[i] = max(dp[i], max(j*(i-j), j*dp[i-j]));
            }
        }
        return dp[n];
    }
};



Given an integer n, break it into the sum of k positive integers, where k >= 2, and maximize the product of those integers.

Return the maximum product you can get.

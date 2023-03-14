class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n==0)
            return 1;
        if(n==1)
            return 10;
        int res = 0;
        res = 10;
        int dp[n];
        dp[0] = 9;
        int x = 9;
        for(int i=1 ; i<n && i<10 ; i++) {
            dp[i] = dp[i-1]*x--;
            res += dp[i];
        }
        
        return res;
    }
};



Given an integer n, return the count of all numbers with unique digits, x, where 0 <= x < 10n.

class Solution {
public:
    int MOD = 1e9+7;
    int recur(int zero, int one, int low, int high, int len, vector<int>&dp) {
        if(len > high) return 0;

        if(dp[len] != -1) return dp[len];

        int res = 0;
        if(zero) {
            int temp = recur(zero, one, low, high, len+zero, dp);
            res = (res + temp)%MOD;
            if(len+zero >= low && len+zero <= high) {
                res = (res + 1)%MOD;
            }
        }

        if(one) {
            int temp = recur(zero, one, low, high, len+one, dp);
            res = (res + temp)%MOD;
            if(len+one >= low && len+one <= high) {
                res = (res + 1)%MOD;
            }
        }

        return dp[len] = res;
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int>dp(high+1, -1);
        int res = recur(zero, one, low, high, 0, dp);
        return res;
    }
};

// TABULATION

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> dp(3,0);
        for(int n: nums) {
            for(int x: vector<int>(dp)) {
                dp[(n+x)%3] = max(dp[(n+x)%3], n+x);
            }
        }
        return dp[0];
    }
};


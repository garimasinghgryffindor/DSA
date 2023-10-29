// IMPORTANT
// DP

class Solution {
public:
    long long minIncrementOperations(vector<int>& nums, int k) {
        vector<long long> dp(3);
        int n = nums.size();
        
        for(int i = 0; i < 3; i++) {
            dp[i] = max(0, k-nums[i]);
        }
        
        for(int i = 3; i < n; i++) {
            vector<long long>ndp(3, 0);
            ndp[0] = dp[1];
            ndp[1] = dp[2];
            ndp[2] = max(0, k-nums[i]) + min({dp[0], dp[1], dp[2]});
            dp = ndp;
        }
        
        return min({dp[0], dp[1], dp[2]});
    }
};

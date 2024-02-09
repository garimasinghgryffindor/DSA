class Solution {
public:
    // Approach 1..
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size(), mx = 1;
        vector<int> res;
        vector<int> dp(n, 1);
        sort(nums.begin(), nums.end());
        
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i]%nums[j] == 0) {
                    if(dp[i] < dp[j]+1) {
                        dp[i] = dp[j] + 1;
                        mx = max(mx, dp[i]);
                    }
                }
            }
        }
        
        int num = -1;
        
        for(int i = n-1; i >= 0; i--) {
            if(dp[i] == mx) {
                if(num == -1 || num%nums[i] == 0) {
                    res.push_back(nums[i]);
                    num = nums[i];
                    mx--;
                }
            }
        }
        
        return res;
    }
};


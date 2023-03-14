class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // let us look at this problem like a subset sum problem
        int sum = 0;
        for(auto x: nums)
            sum+=x;
        
        if(sum%2 != 0)
            return false;
        
        sum = sum/2;
        
        // now here we will apply subsetsum problem
        // 0/1 knapsack
        
        int n = nums.size();
        
        vector<vector<bool>> dp(n+1, vector<bool>(sum+1, false));
        for(int i=0 ; i<n+1 ; i++) {
            dp[i][0] = true; 
        }
        
        for(int i=0 ; i<sum+1 ; i++) {
            dp[0][i] = false;
        }
        
        for(int i=1 ; i<n+1 ; i++) {
            for(int j=1 ; j<sum+1 ; j++) {
                dp[i][j] = dp[i-1][j];
                if(nums[i-1] <= j) {
                    dp[i][j] = dp[i][j] || dp[i-1][j-nums[i-1]];
                }
            }
        }
        
        for(int i=0 ; i<n+1 ; i++) {
            for(int j=0 ; j<sum+1 ; j++) {
                cout<<dp[i][j]<<"  ";
            }
            cout<<endl;
        }
        
        return dp[n][sum];
    }
};



Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.

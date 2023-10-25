// RECURSION
 void recur(vector<int>&nums, int i, int &res, int currSum) {
    if(i < 0) return;
    if(i == 1 || i == 0) {
        currSum += nums[i];
        res = max(currSum, res);
        return;
    }
    
    currSum += nums[i];
    recur(nums, i-2, res, currSum);
    recur(nums, i-3, res, currSum);
}

int rob(vector<int>& nums) {
    int res = 0;
    int n = nums.size();
    recur(nums, n-1, res, 0);
    recur(nums, n-2, res, 0);
    return res;
}


// DP
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0)
            return 0;
        if(n==1)
            return nums[0];
        if(n==2)
            return max(nums[0] , nums[1]);
        vector<int> dp(n , 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0] , nums[1]);
        for(int i=2 ; i<n; i++)
        {
            dp[i] = max(dp[i-2]+nums[i] , dp[i-1]);
        }
        return dp[n-1];
    }
};



You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

class Solution {
public:
    int recur(vector<int>&nums, int target, int idx, int res) {
        if(idx == nums.size()) {
            if(res == target) return 1;
            return 0;
        }

        int plus = recur(nums, target, idx+1, res+nums[idx]);
        int minus = recur(nums, target, idx+1, res-nums[idx]);
        return minus + plus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return recur(nums, target, 0, 0);
    }
};

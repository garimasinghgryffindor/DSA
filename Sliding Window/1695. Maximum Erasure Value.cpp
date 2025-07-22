class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        vector<int>prefixSum(n+1, 0);
        for(int i = 1; i <= n; i++) {
            prefixSum[i] += prefixSum[i-1] + nums[i-1];
        }

        // question boils down to maximum sum subarray with unique elements
        map<int, int> mp;
        int l = -1;
        for(int i = 0; i < n; i++) {
            if(mp.find(nums[i]) == mp.end() || mp[nums[i]] < l) {
                // goodie
                mp[nums[i]] = i;
                res = max(res, prefixSum[i+1] - prefixSum[l+1]);
            } else {
                l = mp[nums[i]];
                mp[nums[i]] = i;
            }
        }

        return res;
    }
};

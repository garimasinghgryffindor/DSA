class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int l = 0, r = 0;
        int n = nums.size();
        int res = 0;
        while(r < n) {
            mp[nums[r]]++;
            if(mp[nums[r]] > k) {
                while(nums[l] != nums[r]) {
                    mp[nums[l]]--;
                    l++;
                }
                mp[nums[l]]--;
                l++;
            }
            res = max(res, r-l+1);
            r++;
        }
        
        return res;
    }
};

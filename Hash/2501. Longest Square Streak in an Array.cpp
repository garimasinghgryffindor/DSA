class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        map<int, int> mp;
        int res = -1;
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < nums.size(); i++) {
            int sqrt_ = sqrt(nums[i]);
            if(sqrt_*sqrt_ == nums[i] && mp.find(sqrt_) != mp.end()) {
                mp[nums[i]] = mp[sqrt_] + 1;
                res = max(res, mp[nums[i]]);
            } else {
                mp[nums[i]] = 1;
            }
        }
        
        return res;
    }
};

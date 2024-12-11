class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int res = 0, n = nums.size();
        sort(nums.begin(), nums.end());
        int l = 0, r = n-1;
        for(int r = 0; r < n; r++) {
            if(nums[r] - nums[l] <= 2*k) {
                res = max(res, r-l+1);
            } else {
                while(nums[r] - nums[l] > 2*k) l++;
            }
        }

        return res;
    }
};

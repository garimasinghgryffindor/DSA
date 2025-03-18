class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int res = 1, n = nums.size();
        int curr = 0;
        int l = 0;

        for(int r = 0; r < n; r++) {
            while((curr & nums[r] )!= 0) {
                curr ^= nums[l];
                l++;
            }

            curr |= nums[r];

            res = max(res, r-l+1);
        }

        return res;
    }
};

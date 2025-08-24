class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int res = 0;
        int curr = 0;
        int curr2 = 0;
        int zero = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(nums[i] == 1) {
                curr++;
            } else {
                zero = 1;
                if(i > 0 && nums[i-1] == 1) {
                    curr2 = curr;
                    curr = 0;
                } else {
                    curr = 0;
                    curr2 = 0;
                }
            }
            res = max(res, curr+curr2);
        }

        return zero ? res : res-1;
    }
};

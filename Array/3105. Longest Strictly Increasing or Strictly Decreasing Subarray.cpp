class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        bool incr = true;
        int len = 1, curr = 1;
        for(int i = 1; i < nums.size(); i++) {
            if(incr) {
                if(nums[i] > nums[i-1]) {
                    curr++;
                } else if(nums[i] < nums[i-1]) {
                    curr = 2;
                    incr = false;
                } else {
                    curr = 1;
                }
            } else {
                if(nums[i] < nums[i-1]) {
                    curr++;
                } else if(nums[i] > nums[i-1]) {
                    curr = 2;
                    incr = true;
                } else {
                    curr = 1;
                }
            }

            len = max(len, curr);
        }

        return len;
    }
};

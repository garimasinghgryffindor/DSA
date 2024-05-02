class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.size()-1;
        while(l < r) {
            if(nums[l] < 0 && nums[r] < 0 || nums[l] > 0 && nums[r] > 0) return -1;
            
            if(abs(nums[l]) == abs(nums[r])) {
                return nums[r];
            } else if(abs(nums[l]) > nums[r]) {
                l++;
            } else {
                r--;
            }
        }
        
        return -1;
    }
};

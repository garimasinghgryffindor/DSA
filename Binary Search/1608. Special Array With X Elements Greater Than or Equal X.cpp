class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        int l = 0, r = nums.size()-1;
        int n = nums.size();
        
        if (nums[n - 1] > n) return n;
        if (nums[0] == 0) return -1;
        int mid = 0;
        
        while(l <= r) {
            mid = l + (r-l)/2;
            if(nums[mid] > mid) {
                l = mid + 1;
            } else if(nums[mid] < mid) {
                r = mid - 1;
            } else {
                return -1;
            }
        }
        
        return nums[mid] > mid ? mid + 1 : mid;
    }
};

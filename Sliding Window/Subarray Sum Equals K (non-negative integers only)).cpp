class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0, l = 0, r = 0, n = nums.size();
        int sum = 0;
        while(l<n && r < n) {
            sum += nums[r];
            if(sum < k) {
                r++;
            } else if(sum == k) {
                res++;
                sum -= nums[l];
                r++;
                l++;
            } else {
                while(sum > k) {
                    sum -= nums[l];
                    l++;
                }
                sum -= nums[r];
            }
        }
        
        return res;
    }
};

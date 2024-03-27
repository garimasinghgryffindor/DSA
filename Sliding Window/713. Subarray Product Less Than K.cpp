class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        if(k <= 1) return 0;
        int sum = 0, prod = 1, l = 0, r = 0;
        while(r < n) {
            prod *= nums[r];int len = r-l;
            
            while(prod >= k) {
                prod /= nums[l];
                l++;
            }
            sum += 1 + r-l;
            
            r++;
        }
        
        return sum;
    }
};

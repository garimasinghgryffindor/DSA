class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long res = 0;
        int bad_idx = -1, l = -1, r = -1;
        int n = nums.size();
        
        for(int i = 0; i < n; i++) {
            if(nums[i] > maxK || nums[i] < minK) {
                bad_idx = i;
                continue;
            }
            if(nums[i] == minK) {
                l = i;
            }
            if(nums[i] == maxK) {
                r = i;
            }
            
            res += max(0, min(l, r) - bad_idx);
        }
        
        return res;
    }
};

class Solution {
public:
    
    void updateBits(vector<int>&count, int num, int updateVal) {
        for(int i = 0; i < 32; i++) {
            if((num >> i) & 1) {
                count[i] += updateVal;
            }
        }
    }
    
    int calOr(vector<int>&count) {
        int val = 0;
        for(int i = 0; i < 32; i++) {
            val = val | ((count[i] > 0) << i);
        }
        return val;
    }
    
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int l = 0, r = 0, n = nums.size(), res = INT_MAX;
        vector<int>count(32, 0);
        
        while(r < n) {
            updateBits(count, nums[r], 1);
            
            while(l <= r && calOr(count) >= k) {
                res = min(res, r-l+1);
                updateBits(count, nums[l], -1);
                l++;
            }
            r++;
        }
        
        return res == INT_MAX ? -1 : res;
    }
};

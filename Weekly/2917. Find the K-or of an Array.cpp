class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        
        for(int i = 0; i < 31; i++) {
            int count = 0;
            for(int j = 0; j < n; j++) {
                if(nums[j] >> i & 1 == 1) {
                    count++;
                    if(count == k) {
                        ans = ans | (1 << i);
                        break;
                    }
                }
            }
        }
        
        return ans;
    }
};

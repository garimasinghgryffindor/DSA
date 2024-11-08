class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        vector<int>res(n, 0);
        res[0] = nums[0];
        for(int i = 1; i < n; i++) {
            res[i] = res[i-1] ^ nums[i];
        }
        
        int num = (1 << maximumBit) - 1;
        for(int i = 0; i < n; i++) {
            res[i] = num ^ res[i];
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};

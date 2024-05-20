class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int res = 0, n = nums.size();
        int mx = 1 << n;
        for(int i = 0; i < mx; i++) {
            int curr = 0;
            for(int j = 0; j < n; j++) {
                if(((1 << j) & i) != 0) {
                    curr = curr ^ nums[j];
                }
            }
            res += curr;
        }
        return res;
    }
};

class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int n = nums.size();
        int mini = 0;
        vector<int>prefixSum(n, 0);
        for(int i=0 ; i<n ; i++) {
            if(i==0) {
                prefixSum[i] = nums[i];
            } else {
                prefixSum[i] = prefixSum[i-1] + nums[i];
            }
            
            mini = min(mini, prefixSum[i]);
        }
        
        return -mini + 1;
    }
};

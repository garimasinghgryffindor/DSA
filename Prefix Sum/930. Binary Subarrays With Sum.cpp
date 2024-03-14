class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        unordered_map<int, int>prefixSum;
        int sum = 0, res = 0;
        for(int i = 0; i < n; i++) {
            sum+=nums[i];
            if(sum == goal) { res++; }
            if(prefixSum.find(sum-goal) != prefixSum.end()) {
                res+=prefixSum[sum-goal];
            }
            prefixSum[sum]++;
        }
        
        return res;
    }
};

// also can be done using sliding window approach

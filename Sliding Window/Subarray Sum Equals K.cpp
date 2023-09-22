// using PREFIX SUM
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0, n = nums.size();
        map<int,int>prefixSum;
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum+=nums[i];
            
            if(sum == k) res++;
            if(prefixSum[sum - k]) {
                res+=prefixSum[sum - k];
            }
            prefixSum[sum]++;
        }
        
        return res;
    }
};


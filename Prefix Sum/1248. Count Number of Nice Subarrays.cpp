class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int n = nums.size();
        for(int i=0 ; i<n ; i++) {
            nums[i] = nums[i]%2;
        }
        
        int prefixSum = 0, res = 0;
        for(int i=0 ; i<n ; i++) {
            prefixSum += nums[i];
            if(prefixSum == k) {
                res++;
            }
            if(mp.find(prefixSum - k) != mp.end()) {
                res += mp[prefixSum - k];
            }
            
            mp[prefixSum]++;
        }
        
        return res;
    }
};

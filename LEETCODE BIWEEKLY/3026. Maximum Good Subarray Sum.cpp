class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans = numeric_limits<long long>::min();
        
        int n = nums.size();
        unordered_map<int, vector<int>> mp;
        vector<long long>prefix(n+1, 0);
        long long sum = 0;
            
        for(int i = 0; i < n; i++) {
            sum = sum + (long long)nums[i];
            prefix[i+1] = sum;
            if(mp.find(nums[i]-k) != mp.end()) {
                for(int x: mp[nums[i]-k]) {
                    ans = max(ans, sum-prefix[x]);
                }
            }
            if(mp.find(k+nums[i]) != mp.end()) {
                for(int x: mp[k+nums[i]]) {
                    ans = max(ans, sum-prefix[x]);
                }
            }
            mp[nums[i]].push_back(i);
        }
        
        if (ans == numeric_limits<long long>::min()) return 0;
        
        return ans;
    }
};

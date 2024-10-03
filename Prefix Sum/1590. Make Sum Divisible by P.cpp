class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        unordered_map<int, int> mp;
        mp[0] = -1;
        long long sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        long long temp = 0;
        
        if(sum%p == 0) return 0;
        int rem = sum%p;
        int res = INT_MAX;
        
        for(int i = 0; i < nums.size(); i++) {
            temp += nums[i];
            int rm = temp%p;
            int req = ((rm - rem)%p + p)%p;
            if(mp.find(req) != mp.end()) {
                res = min(res, i - mp[req]);
            } 
            
            mp[rm] = i;
        }
        
        if(res == INT_MAX || res == nums.size()) return -1;
        return res;
    }
};

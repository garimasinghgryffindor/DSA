class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {
        long long res = 0;
        unordered_map<int,int>mp;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i]%k == 0) {
                res += i;
            } else {
                int required_num = k/gcd(k, nums[i]);
                int frq = mp[required_num];
                res += frq;
            }
            
            for(int j = 1; j <= k; j++) {
                if(nums[i]%j == 0) {
                    mp[j]++;
                }
            }
        }
        
        return res;
    }
};

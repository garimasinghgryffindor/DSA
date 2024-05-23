class Solution {
public:
    int dfs(vector<int>&nums, int k, int idx, unordered_map<int, int>&mp) {
        if(idx == nums.size()) return 1;
        int taken = 0;
        if(!mp[nums[idx]-k] && !mp[nums[idx]+k]) {
            mp[nums[idx]]++;
            taken = dfs(nums, k, idx+1, mp);
            mp[nums[idx]]--;
        }
        
        int nottaken = dfs(nums, k, idx+1, mp);
        return taken+nottaken;
    }
    
    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        return dfs(nums, k, 0, mp)-1;
    }
};

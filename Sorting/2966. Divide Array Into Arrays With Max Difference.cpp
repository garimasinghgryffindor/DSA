class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n/3; i++) {
            if(nums[i*3+2] - nums[i*3] > k) return {};
            
            res.push_back({nums[i*3], nums[i*3+1], nums[i*3+2]});
        }
        
        return res;
    }
};

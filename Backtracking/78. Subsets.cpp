class Solution {
public:
    void recur(vector<int>&nums,vector<vector<int>>&res,int idx, vector<int>temp) {
        if(idx == nums.size()) {
            res.push_back(temp); return;
        }
        
        // not taking
        recur(nums, res, idx+1, temp);
        
        // taking
        temp.push_back(nums[idx]);
        recur(nums, res, idx+1, temp);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        recur(nums, res, 0, {});
        return res;
    }
};

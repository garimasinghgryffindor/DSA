class Solution {
public:
    void recur(vector<int>&nums, int m_or, int&res, int idx, int curr_or) {
        if(idx >= nums.size()) {
            if(m_or == curr_or) res++;
            return;
        }
        
        recur(nums, m_or, res, idx+1, curr_or | nums[idx]);
        recur(nums, m_or, res, idx+1, curr_or);
    }
    
    int countMaxOrSubsets(vector<int>& nums) {
        int max_or = 0;
        for(int x: nums) {
            max_or = max_or | x;
        }
        
        // find the number of subsets with | = max_or
        
        int res = 0;
        
        recur(nums, max_or, res, 0, 0);
        return res;
    }
};

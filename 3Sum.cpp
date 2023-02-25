class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        const size_t len = nums.size();
        if (len < 3)
            return {};
        
        sort(nums.begin(), nums.end());
        
        set<vector<int>> unique_results;
        
        for(int i = 0; i < len - 2; i++) {
            
            int j = i + 1;
            int k = len - 1;
            
            while (j < k) {
            
                const int sum = nums[i] + nums[j] + nums[k];
                if (0 == sum) {
                    unique_results.insert((vector<int>){nums[i], nums[j++], nums[k--]});
                }
                else if (0 > sum)
                    j++;
                else if (0 < sum)
                    k--;
            }
        }
        
        vector <vector <int> > res;
        
        copy(unique_results.begin(), unique_results.end(),back_inserter(res));
        return res;
    }
        
};



LEETCODE 15

  
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
Notice that the solution set must not contain duplicate triplets.



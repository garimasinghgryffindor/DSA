class Solution {
public:
    // using dp 
    int lengthOfLIS(vector<int>& nums) {
        vector<int>lis(nums.size(), 0 );
        lis[0] = 1;
        
        for(int i=1 ; i<nums.size() ; i++) {
            lis[i] = 1;
            for(int j=0 ; j<i ; j++) {
                if(nums[i] > nums[j] && lis[i] < lis[j] + 1) {
                    lis[i] = lis[j] + 1;
                }
            }
        }
        
        return *max_element(lis.begin(), lis.end());
    }
};


// LEETCODE 300

// Given an integer array nums, return the length of the longest strictly increasing subsequence.




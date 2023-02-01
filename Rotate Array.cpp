class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int x = k%nums.size();
        
        vector<int>res(nums.size());
        
        for(int i=0 ; i<nums.size()-x ; i++){
            res[i+x] = nums[i]; 
        }
        
        for(int i=nums.size()-x ; i<nums.size() ; i++){
            res[i-nums.size()+x] = nums[i];
        }
        
        for(int i=0 ; i<nums.size() ; i++){
            nums[i] = res[i];
        }
    }
};

// LEETCODE 189
// Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.



class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int x =0;
        for(int i=0 ; i<nums.size() ; i++){
            if(nums[i]!=0){
                nums[x++] = nums[i];
            }
        }
        for(;x<nums.size() ; x++){
            nums[x] = 0;
        }
    }
};



// LEETCODE 283
// Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

// Note that you must do this in-place without making a copy of the array.

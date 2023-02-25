class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
            return true;
        
        int i=n-2, j=n-1;
        
        while(j>=0) {
            if(nums[i] >= j-i) {
                // A ok
                j = i;
                i = j-1;
            } else {
                i--;
            }
            
            if(j==0)
                break;
            if(i<0)
                return false;
        }
        
        return true;
    }
};



LEETCODE 55

You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.


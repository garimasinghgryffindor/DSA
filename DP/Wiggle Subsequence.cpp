A wiggle sequence is a sequence where the differences between successive numbers strictly alternate between positive and negative. The first difference (if one exists) may be either positive or negative. A sequence with one element and a sequence with two non-equal elements are trivially wiggle sequences.

For example, [1, 7, 4, 9, 2, 5] is a wiggle sequence because the differences (6, -3, 5, -7, 3) alternate between positive and negative.
In contrast, [1, 4, 7, 2, 5] and [1, 7, 4, 5, 5] are not wiggle sequences. The first is not because its first two differences are positive, and the second is not because its last difference is zero.
A subsequence is obtained by deleting some elements (possibly zero) from the original sequence, leaving the remaining elements in their original order.

Given an integer array nums, return the length of the longest wiggle subsequence of nums.
  
  
  
  
GREEDY APPROACH

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) { 
        int valley = 1, peak = 1;
        for(int i=1 ; i<nums.size() ; i++) {
            if(nums[i] > nums[i-1]) 
                peak = valley + 1;
            else if(nums[i] < nums[i-1])
                valley = peak + 1;
        }
        
        return max(peak, valley);
    }
};




DYNAMIC PROGRAMMING APPROACH

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        // DYNAMIC PROGRAMMING APPROACH
        
        int n = nums.size();
        
        vector<int> peak(n, 1);
        vector<int> valley(n, 1);
        
        for(int i=1 ; i<n ; i++) {
            for(int j=0 ; j<i ; j++) {
                if(nums[i] > nums[j]) {
                    // i.e; it is in an increasing subsequence
                    // then look for the decreasing part of it
                    peak[i] = max(peak[i], valley[j] + 1);
                } else if(nums[i] < nums[j]) {
                    valley[i] = max(valley[i], peak[j] + 1);
                }
            }
        }
        
        return max(peak.back(), valley.back());
    }
};

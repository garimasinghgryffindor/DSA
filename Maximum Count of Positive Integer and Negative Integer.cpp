class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int neg=0 , zero=0;
        for(auto ele : nums) {
            if(ele < 0) {
                neg ++;
            } else if(ele == 0) {
                zero++;
            } else {
                break;
            }
        }
        int pos = nums.size()-neg-zero;
        return max(neg, pos);
    }
};


// LEETCODE 2529


// Given an array nums sorted in non-decreasing order, return the maximum between the number of positive integers and the number of negative integers.

// In other words, if the number of positive integers in nums is pos and the number of negative integers is neg, then return the maximum of pos and neg.
// Note that 0 is neither positive nor negative.


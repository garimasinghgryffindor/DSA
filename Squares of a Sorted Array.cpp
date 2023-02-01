class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector <int> res(nums.size());
        int l=0, r=nums.size()-1;
        
        for(int i=nums.size()-1 ; i>=0 ; i--)
        {
            if(abs(nums[r]) > abs(nums[l]))
            {
                res[i] = nums[r] * nums[r--];
            }
            else
            {
                res[i] = nums[l] * nums[l++];
            }
        }
        
        return res;
    }
};

/*

LEETCODE 977

Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

*/


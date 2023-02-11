class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int count = 0;
        for(int i=2 ; i<n ; i++) {
            int s = 0, e = i-1;
            while(s < e) {
                if(nums[s]+nums[e] > nums[i]) {
                    count += e-s;
                    e--;
                } else {
                    s++;
                }
            }
        }
        
        return count;
    }
};


// LEETCODE 611

// Given an integer array nums, return the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle.


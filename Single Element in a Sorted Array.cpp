class Solution {
public:
    int binarySearch(vector<int>&nums, int l , int r) {
        if(l <= r) {
            int mid = l + (r-l)/2;
            // there could be two extreme cases
            if(mid == 0) {
                if(nums[mid]!=nums[mid+1])
                    return nums[mid];
                return -1;
            }
            
            if(mid == nums.size()-1) {
                if(nums[mid]!=nums[mid-1])
                    return nums[mid];
                return -1;
            }
            
            if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1])
                return nums[mid];
            
            // second question -> where to go if the element is not found
            // see normally all the elements will be like->
            //      1  1  2  2  3  3
            //indx  0  1  2  3  4  5
            // even idx and then odd index
            
            if(nums[mid] == nums[mid-1] && mid%2==1) {
                return binarySearch(nums, mid+1, r);
            }
            
            if(nums[mid] == nums[mid-1] && mid%2==0) {
                return binarySearch(nums, l, mid-2);
            }
            
            if(nums[mid] == nums[mid+1] && mid%2==0) {
                return binarySearch(nums, mid+2 , r);
            }
            
            if(nums[mid] == nums[mid+1] && mid%2==1) {
                return binarySearch(nums, l, mid-1);
            }
        }
        
        return -1;
    }
    
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        
        return binarySearch(nums, 0, nums.size()-1);
    }
};



// LEETCODE 540

// You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

// Return the single element that appears only once.

// Your solution must run in O(log n) time and O(1) space.



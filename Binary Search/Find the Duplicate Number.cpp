class Solution {
public:
    int binarySearch(vector<int>nums,int l , int r){
        if(nums[l] == nums[l+1])
            return nums[l];
        if(nums[r] == nums[r-1])
            return nums[r];
        
        int mid = l + (r-l)/2;
        if(mid >= nums[mid]){
            if(nums[mid-1] == nums[mid])
                return nums[mid];
            
            return binarySearch(nums,l,mid-1);
        }
        
        return binarySearch(nums,mid+1 , r);
    }
    
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin() , nums.end());
        int res = binarySearch(nums, 0 , n-1);
        
        return res;
    }
};


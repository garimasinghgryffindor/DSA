class Solution {
public:
    int bin1(vector<int>&nums, int target, int l, int r) {
        if(l > r) return -1;
        int mid = l + (r-l)/2;
        if(nums[mid] == target) {
            if(mid == 0) return mid;
            if(nums[mid-1] < target) return mid;
            return bin1(nums, target, l, mid-1);
        }
        if(nums[mid] > target) {
            return bin1(nums, target, l, mid-1);
        } else {
            return bin1(nums, target, mid+1, r);
        }
    }
    
    int bin2(vector<int>&nums, int target, int l, int r) {
        if(l > r) return -1;
        int mid = l + (r-l)/2;
        if(nums[mid] == target) {
            if(mid == nums.size()-1) return mid;
            if(nums[mid+1] > target) return mid;
            return bin2(nums, target, mid+1, r);
        }
        if(nums[mid] > target) {
            return bin2(nums, target, l, mid-1);
        } else {
            return bin2(nums, target, mid+1, r);
        }
    }
    
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int>res;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int l = bin1(nums, target, 0, n-1);
        if(l == -1) return {};
        int r = bin2(nums, target, 0, n-1);
        
        for(int i = l; i <= r; i++) {
            res.push_back(i);
        }
        return res;
    }
};

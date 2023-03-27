// using modified merge sort

class Solution {
public:
    int merge(vector<int>&nums,int l,int mid,int r) {
        int count = 0;
        int j = mid+1;
        
        for(int i=l ; i<=mid ; i++) {
            while(j<=r && nums[i] > 2LL*nums[j]) {
                j++;
            }
            count += j-(mid+1);
        }
        
        vector<int>temp;
        int left = l, right = mid+1;
        
        while(left <= mid && right <= r) {
            if(nums[left] <= nums[right]) {
                temp.push_back(nums[left++]);
            } else {
                temp.push_back(nums[right++]);
            }
        }
        
        while(left<=mid) {
            temp.push_back(nums[left++]);
        }
        
        while(right<=r) {
            temp.push_back(nums[right++]);
        }
        
        for(int i=l; i<=r ; i++) {
            nums[i] = temp[i-l];
        }
        
        return count;
    }
    
    int mergeSort(vector<int>&nums,int l,int r) {
        int revCount = 0;
        if(r > l) {
            int mid = l + (r-l)/2;
            revCount += mergeSort(nums,l,mid);
            revCount += mergeSort(nums,mid+1,r);
            revCount += merge(nums,l,mid,r);
        }
        return revCount;
    }
    
    int reversePairs(vector<int>& nums) {
        if(nums.size() < 2)
            return 0;
        return mergeSort(nums, 0, nums.size()-1);
    }
};

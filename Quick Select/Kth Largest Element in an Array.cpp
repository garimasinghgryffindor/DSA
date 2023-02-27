class Solution {
public:
    void swap(int &a,int &b) {
        int x = a;
        a = b;
        b = x;
    }
    
    int partition(vector<int>& arr, int l , int r) {
        int pivot = arr[r];
        int i=l-1;
        for(int j=l ; j<=r ; j++) {
            if(arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i+1],arr[r]);
        return i+1;
    }
    
    int quickSort(vector<int>& arr, int l, int r,int target) {
        if(l < r) {
            int p = partition(arr, l ,r);
            if(p == target) {
                return arr[p];
            }
            else if(p < target) {
                return quickSort(arr, p+1, r,target);
            } else {
                return quickSort(arr, l, p-1,target);
            }
        }
        return arr[l];
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        int target = nums.size() - k;
        return quickSort(nums,0,nums.size()-1,target);;
    }
};



LEETCODE 215
  
Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

You must solve it in O(n) time complexity.






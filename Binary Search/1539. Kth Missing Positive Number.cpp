class Solution {
public:
    int binarySearch(vector<int>&arr,int k,int l,int r) {
        if(l>r)
            return r+1+k;
        
        int mid = l + (r-l)/2;
        if(arr[mid] == mid+1) {
            return binarySearch(arr,k,mid+1,r);
        }
        
        if(arr[mid] > mid+1) {
            if(arr[mid]-(mid+1) >=k && mid-1>=0 && arr[mid-1]-(mid) >= k) {
                return binarySearch(arr,k,l,mid-1);
            }
            if(arr[mid]-(mid+1) >= k) {
                // found the range
                return mid+k;
            }
            else {
                return binarySearch(arr,k,mid+1,r);
            }
        }
        
        return mid+1+k;
    }
    
    int findKthPositive(vector<int>& arr, int k) {
        return binarySearch(arr,k,0,arr.size()-1);
    }
};



Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.

Return the kth positive integer that is missing from this array.

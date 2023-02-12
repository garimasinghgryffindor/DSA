class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int maxm = -1;
        for(int i=arr.size()-1 ; i>=0 ; i--) {
            int newMax=maxm;
            if(arr[i] > maxm) {
                newMax = arr[i];
            }
            arr[i] = maxm;
            maxm = newMax;
        }
        
        return arr;
    }
};



LEETCODE 1299
  
Given an array arr, replace every element in that array with the greatest element among the elements to its right, and replace the last element with -1.

After doing so, return the array.

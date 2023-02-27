class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l = 0, r = arr.size()-1;
        
        while(r-l >= k) {
            if(x-arr[l] <= arr[r]-x) {
                r--;
            } else {
                l++;
            }
        }
        
        return vector<int>(arr.begin()+l , arr.begin()+r+1);
    }
};



LEETCODE 658
 
Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order.

An integer a is closer to x than an integer b if:

|a - x| < |b - x|, or
|a - x| == |b - x| and a < b



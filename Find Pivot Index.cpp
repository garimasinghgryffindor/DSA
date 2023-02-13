class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int>prefixSum(n,0);
        prefixSum[0] = nums[0];
        for(int i=1 ; i<n ; i++){
            prefixSum[i] = prefixSum[i-1] + nums[i];
        }
        
        for(int i=0 ; i<n ; i++){
            int sum_lhs , sum_rhs;
            if(i!=0)
                sum_lhs = prefixSum[i-1];
            else 
                sum_lhs = 0;
            if(i!=n-1)
                sum_rhs = prefixSum[n-1] - prefixSum[i];
            else
                sum_rhs = 0;
            if(sum_lhs == sum_rhs){
                return i;
            }
        }
        return -1;
    }
};



LEETCODE 724


Given an array of integers nums, calculate the pivot index of this array.

The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right.

If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. This also applies to the right edge of the array.

Return the leftmost pivot index. If no such index exists, return -1.


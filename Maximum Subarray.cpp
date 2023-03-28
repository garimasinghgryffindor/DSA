Kadane's algorithm

class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        int sum = INT_MIN, tempSum=0;
        for(int i=0 ; i<arr.size() ; i++) {
            tempSum+=arr[i];
            if(tempSum>sum) {
                sum = tempSum;
            }
            if(tempSum < 0) {
                tempSum = 0;
            }
        }
        
        return sum;
    }
};

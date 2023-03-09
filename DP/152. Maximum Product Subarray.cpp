// brute force -> leads to TLE

// class Solution {
// public:
//     int maxProduct(vector<int>& nums) {
//         // using dp
//         int n = nums.size();
//         int res = INT_MIN;
        
//         vector<vector<int>> dp(n, vector<int>(n,0));
//         // int dp[n][n];
//         for(int i=0 ; i<n ; i++) {
//             dp[i][i] = nums[i];
//         }
        
//         for(int i=0 ; i<n ; i++) {
//             for(int j=i ; j<n ; j++) {
//                 if(i==j)
//                     dp[i][j] = nums[i];
//                 else
//                     dp[i][j] = nums[j] * dp[i][j-1];
                
//                 res = max(res, dp[i][j]);
//             }
//         }
        
//         return res;
//     }
// };


Optimized approach:
First of all, Let's think about all the patterns that we can observe in this problem.

If all the numbers are positive the product is always increasing.
But when it comes to negative numbers, It gets alot more tricky as the product of two negatives, is a positive.
When we have a vector of all negatives, the signs of the product will be alternating.
eg. {-1,-2,-3,-4,-5} => -1, 2, -6, 24, -120
        
so, to find maximum in such case, we need to track both maximum and minimum.
example, in {-1,-2,-3} max of first two elements will be 2 and min will be -2
but when combined with the third element -3, our min will become -2*-3 = 6 which is our desired answer.
I hope the reason of storing minimum is pretty clear now.




class Solution {
public:
    void swap(int &x,int &y) {
        int temp = x;
        x = y;
        y = temp;
    }
    
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxx=nums[0], minx=nums[0];
        int res = nums[0];
        
        for(int i=1 ; i<n ; i++) {
            if(nums[i] < 0) {
                // it is a negative number
                // then maxx and minx will interchange
                swap(maxx,minx);
            }
            
            maxx = max(maxx*nums[i], nums[i]);
            minx = min(minx*nums[i], nums[i]);
            res = max(res, maxx);
        }
        
        return res;
    }
};

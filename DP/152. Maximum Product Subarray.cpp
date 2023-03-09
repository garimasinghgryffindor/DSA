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

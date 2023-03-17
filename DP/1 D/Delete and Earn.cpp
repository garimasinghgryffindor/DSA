// RECURSIVE
// TLE
// class Solution {
// public:
//     int res = 0;
    
//     void recur(unordered_map<int,int> mp,int currRes) {
//         if(mp.empty())
//             return;
        
//         for(auto x: mp) {
//             // element selected
//             unordered_map<int,int> mp2;
//             int ele = x.first;
//             int tempRes=currRes;
//             tempRes += ele;
            
//             for(auto y: mp) {
//                 if(y.first == ele) {
//                     if(y.second-1 != 0 ) {
//                         mp2[y.first] = y.second-1;
//                     }
//                 }
//                 else if(y.first == ele-1) {
//                     // do nothing
//                 }
//                 else if(y.first == ele+1) {
//                     // do nothing
//                 }
//                 else {
//                     // do something
//                     mp2[y.first] = y.second;
//                 }
//             }
            
//             res = max(res, tempRes);
//             recur(mp2, tempRes);

            
//             // element not selected
//             // automatically happens when the loop continues
//         }
//     }
    
//     int deleteAndEarn(vector<int>& nums) {
//         unordered_map<int,int> mp;
//         for(auto x: nums)
//             mp[x]++;
        
//         recur(mp,0);
        
//         return res;
//     }
// };



// DP
// Tabulation

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = 10001;
        
        vector<int> sum(n,0);
        vector<int> dp(n,0);
        
        for(auto n: nums) {
            sum[n]+=n;
        }
        
        dp[0] = 0;
        dp[1] = sum[1];
        
        for(int i=2 ; i<n ; i++) {
            dp[i] = max(dp[i-2]+sum[i], dp[i-1]);
        }
        
        return dp[n-1];
    }
};




You are given an integer array nums. You want to maximize the number of points you get by performing the following operation any number of times:

Pick any nums[i] and delete it to earn nums[i] points. Afterwards, you must delete every element equal to nums[i] - 1 and every element equal to nums[i] + 1.
Return the maximum number of points you can earn by applying the above operation some number of times.

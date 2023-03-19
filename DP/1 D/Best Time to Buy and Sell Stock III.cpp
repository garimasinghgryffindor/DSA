// MEMOIZATION

// class Solution {
// public:
//     int recur(int n,vector<int>prices,int index,int k,bool buy,vector<vector<vector<int>>>&dp) {
//         if(index >= n || k>=2)
//             return 0;
        
//         if(buy) {
//             if(dp[index][0][k]!=-1)
//                 return dp[index][0][k];
//         }
//         else {
//             if(dp[index][1][k]!=-1)
//                 return dp[index][1][k];
//         }
        
//         int tempRes = 0;
//         if(buy) {
//             // if buying
//             tempRes = -prices[index] + recur(n,prices,index+1,k,!buy,dp);
            
//             // if leaving
//             tempRes = max(tempRes, recur(n,prices,index+1,k,buy,dp));
//             return dp[index][0][k] = tempRes;
//         }
//         else {
//             // if selling
//             tempRes = prices[index] + recur(n,prices,index+1,k+1,!buy,dp);
            
//             // if leaving
//             tempRes = max(tempRes, recur(n,prices,index+1,k,buy,dp));
//             return dp[index][1][k] = tempRes;
//         }
//     }
    
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         bool buy = true;
//         vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(2,-1)));
//         // buy => 0
//         // sell => 1
//         return recur(n,prices,0,0,buy,dp);
//     }
// };




// TABULATION

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        bool buy = true;
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        
        for(int i=n-1 ; i>=0 ; i--) {
            for(int buy = 0 ; buy<=1 ; buy++) {
                for(int k=1 ; k<=2 ; k++) {
                    if(buy) {
                        dp[i][buy][k] = max(-prices[i] + dp[i+1][0][k], dp[i+1][1][k]);
                    } else {
                        dp[i][buy][k] = max(prices[i] + dp[i+1][1][k-1], dp[i+1][0][k]);
                    }
                }
            }
        }
        
        return dp[0][1][2];
    }
};

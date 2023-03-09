// Recursive

// class Solution {
// public:
//     int recur(vector<int>prices, int day, bool buy) {
//         if(day >= prices.size()) {
//             return 0;
//         }
        
//         int ans1 = recur(prices, day+1, buy);
        
//         int ans2 = 0;
//         if(buy) {
//             ans2 = -prices[day] + recur(prices, day+1, !buy);
//         } else {
//             ans2 = +prices[day] + recur(prices, day+2, !buy);
//         }
        
//         return max(ans1, ans2);
//     }
    
//     int maxProfit(vector<int>& prices) {
//         int day = 0;
//         bool buy = true;
//         return recur(prices, day, buy);
//     }
// };

//buy cooldown.. sell cooldown cooldown....  buy sell cooldown.... buy sell




// Tabulation

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int day = 0;
        int n = prices.size();
        
        vector<vector<int> > dp(n+2, vector<int>(2));
        
        for(int day=n+1 ; day>=0 ; day--) {
            for(int buy=0 ; buy<=1 ; buy++) {
                int ans = dp[day][buy];
                
                if(day >= n) {
                    ans = 0;
                }
                else {
                    int ans1 = dp[day+1][buy], ans2 = 0;
                    
                    if(buy) {
                        ans2 = -prices[day] + dp[day+1][0];
                    } else {
                        ans2 = +prices[day] + dp[day+2][1];
                    }
                    
                    ans = max(ans1, ans2);
                }
                
                dp[day][buy] = ans;
            }
        }
        
        return dp[0][1];
        
    }
};



You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).


// USING RECURSION
class Solution {
public:
    int recur(vector<int>&coins, int idx, int amount) {
        if(amount == 0) return 0;
        if(amount < 0) return -1;
        if(idx >= coins.size()) return -1;
        
        // either take current coin 
        int ret1 = recur(coins, idx, amount-coins[idx]);
        int coins1 = 1 + ret1;
        
        // or not
        int ret2 = recur(coins, idx+1, amount);
        int coins2 = ret2;
        
        if(ret1 == -1 && ret2 == -1) return -1;
        if(ret1 == -1) return coins2;
        if(ret2 == -1) return coins1;
        return min(coins1, coins2);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        return recur(coins,0,amount);
    }
};


// USING MEMOIZATION
class Solution {
public:
    int recur(vector<int>&coins,int idx,int amount,vector<vector<int>>&dp) {
        if(amount == 0) return 0;
        if(amount < 0) return -1;
        if(idx >= coins.size()) return -1;
        
        if(dp[idx][amount] != -2) return dp[idx][amount];
        
        // either take current coin 
        int ret1 = recur(coins, idx, amount-coins[idx], dp);
        int coins1 = 1 + ret1;
        
        // or not
        int ret2 = recur(coins, idx+1, amount, dp);
        int coins2 = ret2;
        
        if(ret1 == -1 && ret2 == -1) return dp[idx][amount] = -1;
        if(ret1 == -1) return dp[idx][amount] = coins2;
        if(ret2 == -1) return dp[idx][amount] = coins1;
        return dp[idx][amount] = min(coins1, coins2);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1, -2));
        return recur(coins,0,amount,dp);
    }
};


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int>dp(amount+1);
        dp[0] = 0;
        
        sort(coins.begin(), coins.end());
        for(int i=1 ; i<amount+1 ; i++) {
            dp[i] = INT_MAX;
            
            for(auto coin: coins) {
                if(i-coin < 0) break;
                
                if(dp[i-coin] != INT_MAX) {
                    dp[i] = min(dp[i], 1 + dp[i-coin]);
                }
            }
        }
        
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};



You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

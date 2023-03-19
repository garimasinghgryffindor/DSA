// Recursion
// TLE

// class Solution {
// public:
//     int recur(vector<int>prices,int index,bool buy,int currRes) {
//         if(index >= prices.size())
//             return 0;
        
//         int tempRes=0;
//         if(buy) {
//             // i can either buy the stock  or leave it and go to next one
//             tempRes = currRes-prices[index] + recur(prices,index+1,!buy,tempRes);
            
//             // leave it
//             int x = recur(prices,index+1,buy,currRes);
            
//             tempRes = max(tempRes, x);
//         } else {
//             // selling the stock
//             tempRes = currRes+prices[index] + recur(prices,index+1,!buy,tempRes);
            
//             // leave it
//             int x = recur(prices,index+1,buy,currRes);
//             tempRes = max(tempRes, x);
//         }
        
//         return tempRes;
//     }
    
//     int maxProfit(vector<int>& prices) {
//         bool buy = true;
//         return recur(prices,0,buy,0);
//     }
// };



// MEMOIZATION

// class Solution {
// public:
//     int recur(vector<int>prices,int index,bool buy,int currRes,vector<int>&dpBuy,vector<int>&dpSell) {
//         if(index >= prices.size())
//             return 0;
        
//         if(buy==true && dpBuy[index]!=-1)
//             return dpBuy[index];
        
//         if(buy==false && dpSell[index]!=-1)
//             return dpSell[index];
        
//         int tempRes=0;
//         if(buy) {
//             // i can either buy the stock  or leave it and go to next one
//             tempRes = currRes-prices[index] + recur(prices,index+1,!buy,tempRes,dpBuy,dpSell);
            
//             // leave it
//             int x = recur(prices,index+1,buy,currRes,dpBuy,dpSell);
            
//             tempRes = max(tempRes, x);
//         } else {
//             // selling the stock
//             tempRes = currRes+prices[index] + recur(prices,index+1,!buy,tempRes,dpBuy,dpSell);
            
//             // leave it
//             int x = recur(prices,index+1,buy,currRes,dpBuy,dpSell);
//             tempRes = max(tempRes, x);
//         }
        
//         if(buy){
//             dpBuy[index] = tempRes;
//         }
//         else {
//             dpSell[index] = tempRes;
//         }
//         return tempRes;
//     }
    
//     int maxProfit(vector<int>& prices) {
//         bool buy = true;
//         vector<int>dpBuy(prices.size(),-1), dpSell(prices.size(),-1);
//         return recur(prices,0,buy,0,dpBuy,dpSell);
//     }
// };



// TABULATION

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy = -prices[0], sell=0;
        
        for(int i=1 ; i<n ; i++) {
            buy = max(buy, sell-prices[i]);
            sell = max(sell, buy+prices[i]);
        }
        return sell;
    }
};

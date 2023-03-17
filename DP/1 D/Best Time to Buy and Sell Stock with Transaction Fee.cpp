// RECURSION
// class Solution {
// public:
//     int res = 0;
    
//     void recur(vector<int>prices, int fee, bool buy, int index,int currRes) {
//         if(index == prices.size())
//             return;
        
//         int tempRes = currRes;
//         if(buy) {
//             // if I have to buy
//             // i can either buy or leave it
            
            
//             // first situation
//             // i am buying the stock
//             tempRes-=prices[index];
//             recur(prices,fee,!buy,index+1,tempRes);
            
//             // second situation
//             // i am leaving it
//             recur(prices,fee,buy,index+1,currRes);
            
//         } else {
//             // if I have to sell
//             // I can either sell or leave it
            
            
//             // first case
//             // selling the stock
//             tempRes+=prices[index]-fee;
//             res=max(res,tempRes);
//             recur(prices, fee,!buy,index+1,tempRes);
            
//             // second case
//             // leaving it
//             recur(prices,fee,buy,index+1,currRes);
//         }
//     }
    
//     int maxProfit(vector<int>& prices, int fee) {
//         bool buy = true;
//         // buy=false -> sell
        
//         recur(prices, fee, buy, 0,0);
        
//         return res;
//     }
// };



// DP
// Tabulation

class Solution {
public:
    
    int maxProfit(vector<int>& prices, int fee) {
        bool buy = true;
        // buy=false -> sell
        
        int buyRes=-prices[0],sellingRes=0;
        
        for(int i=1 ; i<prices.size() ; i++) {
            buyRes=max(buyRes, sellingRes-prices[i]);
            sellingRes=max(sellingRes, buyRes+prices[i]-fee);
        }
        
        return sellingRes;
    }
};

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+2);
        
        // from the final step I will either follow a path which is one step away or which is two step away
        // final step is beyond the last element.
        
        dp[0] = 0;
        dp[1] = 0;
        for(int i = 2 ; i<n+2 ; i++) {
            if(i==2) {
                dp[i] = min(dp[i-1]+cost[i-1 -1], dp[i-2]);
                continue;
            } 
            dp[i] = min(dp[i-1]+cost[i-1 -1],  dp[i-2]+cost[i-2-1]);
        }
        
        return dp[n+1];
    }
};

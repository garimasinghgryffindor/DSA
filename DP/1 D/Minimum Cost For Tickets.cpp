// RECURSIVE
// TLE

class Solution {
public:
    int recur(int n,vector<int>days,vector<int>costs,int index) {
        // base case
        if(index>=n)
            return 0;
        
        // 1 day pass
        int choice1 = costs[0] + recur(n,days,costs,index+1);
        
        // 7 day pass
        int findIndex=index;
        for(findIndex ; findIndex<n && days[findIndex]<days[index]+7 ; findIndex++);       
        int choice2 = costs[1] + recur(n,days,costs,findIndex);
        
        // 30 day pass
        for(findIndex=index ; findIndex<n && days[findIndex]<days[index]+30 ; findIndex++);
        int choice3 = costs[2] + recur(n,days,costs,findIndex);
    
        return min(choice1, min(choice2,choice3));
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        return recur(days.size(),days,costs,0);
    }
};




// MEMOIZATION
// DP

class Solution {
public:
    int recur(int n,vector<int>days,vector<int>costs,int index,vector<int>&dp) {
        // base case
        if(index>=n)
            return 0;
        
        if(dp[index]!=-1)
            return dp[index];
        
        // 1 day pass
        int choice1 = costs[0] + recur(n,days,costs,index+1,dp);
        
        // 7 day pass
        int findIndex=index;
        for(findIndex ; findIndex<n && days[findIndex]<days[index]+7 ; findIndex++);       
        int choice2 = costs[1] + recur(n,days,costs,findIndex,dp);
        
        // 30 day pass
        for(findIndex=index ; findIndex<n && days[findIndex]<days[index]+30 ; findIndex++);
        int choice3 = costs[2] + recur(n,days,costs,findIndex,dp);
    
        dp[index] = min(choice1, min(choice2,choice3));
        
        return dp[index];
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int>dp(days.size(), -1);
        return recur(days.size(),days,costs,0,dp);
    }
};




// DP
// TABULATION

class Solution {
public:
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n+1,INT_MAX );
        dp[n] = 0;
        
        for(int i=n-1 ; i>=0 ; i--) {
            // 1 day pass
            int choice1 = costs[0] + dp[i+1];

            // 7 day pass
            int findIndex=i;
            for(findIndex ; findIndex<n && days[findIndex]<days[i]+7 ; findIndex++);       
            int choice2 = costs[1] + dp[findIndex];

            // 30 day pass
            for(findIndex=i; findIndex<n && days[findIndex]<days[i]+30 ; findIndex++);
            int choice3 = costs[2] + dp[findIndex];
            
            dp[i] = min(choice1, min(choice2,choice3));
        }
        
        return dp[0];
    }
};



// RECURSION

class Solution {
public:
    int recur(vector<int>&satisfaction,int i,int freq,int n) {
        // base case
        if(i>=n)
            return 0;
        
        int res = max(freq*satisfaction[i]+recur(satisfaction,i+1,freq+1,n) , recur(satisfaction,i+1,freq,n));
        
        return res;
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int res = recur(satisfaction,0,1,satisfaction.size());
        return res;
    }
};




// MEMOIZATION

class Solution {
public:
    int dp[501][501];
    
    int recur(vector<int>&satisfaction,int i,int freq,int n) {
        // base case
        if(i>=n)
            return 0;
        
        if(dp[i][freq] != 0) return dp[i][freq];
        
        int res = max(freq*satisfaction[i]+recur(satisfaction,i+1,freq+1,n) , recur(satisfaction,i+1,freq,n));
        
        return (dp[i][freq] = res);
    }
    
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int res = recur(satisfaction,0,1,satisfaction.size());
        return res;
    }
};




// DP
class Solution {
public:  
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        
        int n = satisfaction.size();
        
        vector<vector<int>>dp(n+1, vector<int>(n+2,0));
            //.    ind freq
        
        for(int i=n ; i>0 ; i--) {
            dp[n][i] = 0;
        }
        
        
        for(int i=n-1 ; i>=0 ; i--) {
            // these are all the indices
            for(int j=n ; j>0 ; j--) {
                // these are the frequencies
                dp[i][j] =  max(j*satisfaction[i]+dp[i+1][j+1], dp[i+1][j]);
            }
        }        
        
        int res = dp[0][1];
        return res;
    }
};




// GREEDY

class Solution {
public:  
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int n = satisfaction.size();
        int res = 0, total = 0;
        
        for(int i=n-1 ; i>=0 && satisfaction[i] > -total ; i--) {
            total+=satisfaction[i];
            res+=total;
        }
        
        return res;
    }
};

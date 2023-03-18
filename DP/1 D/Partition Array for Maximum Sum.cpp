// RECURSIVE
// TLE

class Solution {
public:
    int recur(int n,vector<int>arr,int k,int index) {
        // base case
        if(index>=n)
            return 0;
        
        // the choices we have
        // 1,2....k
        int mx = 0;
        int currRes=0;
        int res = 0;
        for(int i=0 ; i<k ; i++) {
            if(index+i>=n)
                break;
            int currNewNumber = arr[index+i];
            mx = max(mx, currNewNumber);
            
            currRes = mx*(i+1) + recur(n,arr,k,index+i+1);
            res = max(res,currRes);
        }
        
        return res;
    }
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        return recur(n,arr,k,0);
    }
};



// MEMOIZATION
// TLE

class Solution {
public:
    int recur(int n,vector<int>arr,int k,int index,vector<int>&dp) {
        // base case
        if(index>=n)
            return 0;
        
        if(dp[index]!=-1)
            return dp[index];
        
        // the choices we have
        // 1,2....k
        int mx = 0;
        int currRes=0;
        int res = 0;
        for(int i=0 ; i<k ; i++) {
            if(index+i>=n)
                break;
            int currNewNumber = arr[index+i];
            mx = max(mx, currNewNumber);
            
            currRes = mx*(i+1) + recur(n,arr,k,index+i+1,dp);
            res = max(res,currRes);
        }
        
        dp[index] = res;
        return dp[index];
    }
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int>dp(n+1,-1);
        return recur(n,arr,k,0,dp);
    }
};





// DP
// TABULATION

class Solution {
public:
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int>dp(n+1,-1);
        
        // base case
        dp[n] = 0;
        
        
        for(int i=n-1 ; i>=0 ; i--) {
            // the choices we have
            // 1,2....k
            int res = 0;
            int mx = 0;
            int currRes=0;
            for(int j=0 ; j<k ; j++) {
                if(j+i>=n)
                    break;
                int currNewNumber = arr[j+i];
                mx = max(mx, currNewNumber);

                currRes = mx*(j+1) + dp[i+j+1];
                res = max(res,currRes);
            }
            
            dp[i] = res;
        }
        
        return dp[0];  
    }
};



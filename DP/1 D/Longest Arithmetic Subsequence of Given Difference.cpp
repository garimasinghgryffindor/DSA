// RECURSIVE
// TLE

class Solution {
public:
    int recur(vector<int>arr,int dif,int index) {
        if(index >= arr.size())
            return 0;
        
        int len = 1;
        // our choices
        for(int i=index+1 ; i<arr.size() ; i++) {
            if(arr[i]-arr[index] == dif) {
                // if it matches I have two choices either take it or leave it
                int tempLen = 1;
                tempLen += recur(arr,dif,i);
                len = max(len, tempLen);
                break;
            }
        }
        
        return len;
    }
    
    int longestSubsequence(vector<int>& arr, int difference) {
        int res = 0;
        for(int i=0 ; i<arr.size() ; i++) {
            int ans = recur(arr,difference,i);
            res = max(res, ans);
        }
        return res;
    }
};



// MEMOIZATION
// TLE

class Solution {
public:
    int recur(vector<int>arr,int dif,int index,vector<int>&dp) {
        if(index >= arr.size())
            return 0;
        
        if(dp[index]!=-1)
            return dp[index];
        
        int len = 1;
        // our choices
        for(int i=index+1 ; i<arr.size() ; i++) {
            if(arr[i]-arr[index] == dif) {
                // if it matches I have two choices either take it or leave it
                int tempLen = 1;
                tempLen += recur(arr,dif,i,dp);
                len = max(len, tempLen);
                break;
            }
        }
        
        dp[index] = len;
        return dp[index];
    }
    
    int longestSubsequence(vector<int>& arr, int difference) {
        int res = 0;
        for(int i=0 ; i<arr.size() ; i++) {
            vector<int>dp(arr.size(),-1);
            int ans = recur(arr,difference,i,dp);
            res = max(res, ans);
        }
        return res;
    }
};




// TABULATION

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int res = 0;
        int n = arr.size();
        vector<int>dp(20001);
        for(int i=0 ; i<n ; i++) {
            int num = arr[i]+10000;
            dp[num] = (num-difference>=0 && num-difference<20001 ? dp[num-difference]:0) + 1;
            res = max(res, dp[num]);
        }
        
        return res;
    }
};

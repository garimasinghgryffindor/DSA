// using LIS

// RECURSION
class Solution {
public:
    int recur(string &s, int &k, int idx, int prev) {
        int n = s.length();
        if(idx == n) return 0;
        
        int res = 0;
        if(prev == -1 || abs(s[idx]-prev) <= k) {
            res = 1 + recur(s, k, idx+1, s[idx]);
        }
        
        res = max(res, recur(s, k, idx+1, prev));
        
        return res;
    }
    int longestIdealString(string s, int k) {
        int res = recur(s, k, 0, -1);
        return res;
    }
};
// TLE


// MEMOIZATION
class Solution {
public:
    vector<vector<int>> dp;
    int recur(string &s, int &k, int idx, int prev) {
        int n = s.length();
        if(idx == n) return 0;
        if(dp[idx+1][prev+1] != -1) return dp[idx+1][prev+1];
        
        int res = 0;
        if(prev == -1 || abs(s[idx]-s[prev]) <= k) {
            res = 1 + recur(s, k, idx+1, idx);
        }
        
        res = max(res, recur(s, k, idx+1, prev));
        
        return dp[idx+1][prev+1] = res;
    }
    int longestIdealString(string s, int k) {
        int n = s.length();
        dp.resize(n+1, vector<int>(n+1, -1));
        int res = recur(s, k, 0, -1);
        return res;
    }
};
// MLE


// TABULATION
class Solution {
public:
    int longestIdealString(string s, int k) {
        int n = s.length();
        vector<int>dp(n+1, 1);
        dp[0] = 0;
        int res = 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(abs(s[i]-s[j]) <= k) {
                    dp[i+1] = max(dp[i+1], 1 + dp[j+1]);
                }
            }
            res = max(res, dp[i+1]);
        }
        
        return res;
    }
};
// TLE



// TABULATION
// ANOTHER APPROACH
// The intuition behind this solution is to iterate through the given string and for each character, determine the count of 
// consecutive characters within a range of k characters by checking alphabetically to the left and right of the current element until 
// k and keeping the maximum count. We then update the count of the current character based on the maximum count of surrounding 
// characters.
class Solution {
public:
    int find(int idx, int k, vector<int>&dp) {
        int res = 0, cnt=0;
        int currIdx = idx;
        
        while(currIdx >= 0 && cnt<=k){
            res = max(res, dp[currIdx]);
            currIdx--;
            cnt++;
        }
        
        currIdx = idx;
        cnt = 0;
        
        while(currIdx<26 && cnt<=k){
            res = max(res, dp[currIdx]);
            currIdx++;
            cnt++;
        }
        
        return res;
    }
    
    int longestIdealString(string s, int k) {
        int n = s.length();
        int res = 0;
        int cnt = 0;
        
        vector<int>dp(26, 0);
        
        for(int i = 0; i < n; i++) {
            int x = s[i]-'a';
            dp[x] = find(x , k, dp)+1;
            res = max(res, dp[x]);
        }
        
        return res;
    }
};








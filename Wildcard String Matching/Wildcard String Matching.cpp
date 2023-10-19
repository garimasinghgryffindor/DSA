// RECURSION
class Solution {
public:
    bool recur(string&s,string&p,int i,int j) {
        if(i < 0 && j < 0) return true;
        if(j < 0 && i >= 0) return false;
        if(i < 0 && j >= 0) {
            for(int k = 0; k <= j; k++) {
                if(p[k] != '*') return false;
            }
            return true;
        }
        
        if(s[i] == p[j] || p[j] == '?') return recur(s,p,i-1,j-1);
        if(p[j] == '*') {
            return recur(s,p,i-1,j) || recur(s,p,i,j-1);
        }
        return false;
    }
    
    bool isMatch(string s, string p) {
        // using Recursion
        int n = s.length(), m = p.length();
        return recur(s,p,n-1,m-1);
    }
};


// MEMOIZATION
class Solution {
public:
    bool recur(vector<vector<int>>&dp,string&s,string&p,int i,int j) {
        if(dp[i+1][j+1] != -1) return dp[i+1][j+1];
        
        if(i < 0 && j < 0) return true;
        if(j < 0 && i >= 0) return false;
        if(i < 0 && j >= 0) {
            for(int k = 0; k <= j; k++) {
                if(p[k] != '*') { return dp[i+1][j+1] = false; }
            }
            return dp[i+1][j+1] = true;
        }
        
        if(s[i] == p[j] || p[j] == '?') return dp[i+1][j+1] = recur(dp,s,p,i-1,j-1);
        if(p[j] == '*') {
            return dp[i+1][j+1] = recur(dp,s,p,i-1,j) || recur(dp,s,p,i,j-1);
        }
        return dp[i+1][j+1] = false;
    }
    
    bool isMatch(string s, string p) {
        // using Memoization
        int n = s.length(), m = p.length();
        vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
        return recur(dp,s,p,n-1,m-1);
    }
};


// TABULATION
class Solution {
public:
    bool isMatch(string s, string p) {
        // using Tabulation
        int n = s.length(), m = p.length();
        vector<vector<bool>>dp(n+1, vector<bool>(m+1, false));
        dp[0][0] = true;
        
        for(int i = 1; i < n; i++) {
            dp[i][0] = false;
        }
        
        for(int j = 1; j <= m; j++) {
            bool flag = true;
            for(int k = 1; k <= j; k++) {
                if(p[k-1] != '*') { dp[0][j] = false; flag = false; break;}
            }
            if(flag) dp[0][j] = true;
        }
        
        
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(s[i-1] == p[j-1] || p[j-1] == '?') 
                    dp[i][j] = dp[i-1][j-1];
                else {
                    if(p[j-1] == '*') 
                        dp[i][j] = dp[i-1][j] || dp[i][j-1];
                    else dp[i][j] = false;
                }
            }
        }
        
        return dp[n][m];
    }
};




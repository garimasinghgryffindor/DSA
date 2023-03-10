// RECURSION

// class Solution {
// public:
//     bool recur(string s,string p,int i, int j) {
//         if(j==p.length()) {
//             return i == s.length();
//         }
        
//         bool match = i<s.length() && (s[i]==p[j] || p[j]=='.');
        
//         if(j+1<p.length() && p[j+1]=='*') {
//             // if the repetition of the non-*/. in R.E. is to be ignored
//             return recur(s,p,i,j+2) || (match && recur(s,p,i+1,j));
//             // so basically either we are considering the repetition or not
//         }
        
//         return match && recur(s,p,i+1,j+1);
    
//     }
    
//     bool isMatch(string s, string p) {
//         return recur(s,p,0,0);
//     }
// };


// DP
class Solution {
public:
    
    bool isMatch(string s, string p) {
        vector<vector<int>>dp(s.length()+1, vector<int>(p.length()+1, 0));
        return helper(s,p,0,0,dp);
    }
    
    bool helper(string s, string p, int i, int j,vector<vector<int>> &dp) 
    {
        dp[s.length()][p.length()] = 1;
        
        for(int i=s.length() ; i>=0 ; i--) {
            for(int j=p.length()-1 ; j>=0 ; j--) {
                bool match = i<s.length() && (s[i] == p[j] || p[j]=='.');
                
                if(j+1<p.length() && p[j+1]=='*') {
                    dp[i][j] = dp[i][j+2] || (match && dp[i+1][j]);
                } else {
                    dp[i][j] = match && dp[i+1][j+1];
                }
            }
        }
        
        return dp[0][0];
    }
};




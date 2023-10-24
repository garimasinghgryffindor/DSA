class Solution {
public:
//     // Recursion
//     bool recur(string&s, string &ans, int l, int r) {
//         // if(l > r) return false;
//         // if(l == r) { if(ans.length() < r-l+1) ans = s.substr(l,r-l+1); return true; }
//         // if(l == r-1) {
//         //     if(s[l] == s[r]) { if(ans.length() < r-l+1) ans = s.substr(l,r-l+1); return true; }
//         //     else return false;
//         // }
        
//         if(s[l] == s[r]) {
//             if(recur(s,ans,l+1,r-1)) {
//                 if(ans.length() < r-l+1) {
//                     ans = s.substr(l,r-l+1);
//                 }
//                 return true;
//             }
//         }
//         return false;
//     }
    
    // DP
    string longestPalindrome(string s) {
        string ans = "";
        int n = s.length();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        
        for(int i = 0; i < n; i++) { dp[i][i] = 1; ans = s[0]; }
        for(int i = 0; i < n-1; i++) {
            if(s[i] == s[i+1]) {
                dp[i][i+1] = 2;
                ans = s.substr(i,2);
            }
        }
        
        for(int i = 3; i <= s.length(); i++) {
            for(int j = 0; j < s.length()-i+1; j++) {
                int left = j, right = j+i-1;
                if(s[left] == s[right]) {
                    if(dp[left+1][right-1] != -1) {
                        // A Ok
                        dp[left][right] = i;
                        if(ans.length() < i) {
                            ans = s.substr(left, i);
                        }
                    }
                }
            }
        }
        
        return ans;
    }
};

class Solution {
public:
    int countSubstrings(string str) {
        int n = str.length();
        int res = 0;
        bool dp[n][n];
        
        int maxLength = 0, start = 0;
        memset(dp, 0, sizeof(dp));
        for(int i=0 ; i<n ; i++) {
            dp[i][i] = true;
            res++;
        }
        
        for(int i=0 ; i<n-1 ; i++) {
            if(str[i]==str[i+1]) {
                dp[i][i+1] = true;
                res++;
            }
        }

        for(int i=3 ; i<=n ; i++) {
            for(int j=0 ; j<n-i+1 ; j++) {
                int k = i+j-1;
                if(dp[j+1][k-1] && str[j]==str[k]) {
                    dp[j][k] = true;
                    res++;
                }
            }
        }

        return res;
    }
};

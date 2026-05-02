class Solution {
public:
    int rotatedDigits(int n) {
        vector<int>dp(n+1, 0);
        int res = 0;

        for(int i = 0; i <= n; i++) {
            if(i < 10) {
                if(i == 0 || i == 8 || i == 1) dp[i] = 1;
                else if(i == 2 || i == 5 || i == 6 || i == 9) {
                    dp[i] = 2;
                    res++;
                }
            } else {
                int pref = dp[i / 10];
                int suff = dp[i % 10];

                if(pref == 1 && suff == 1) dp[i] = 1;
                else if(pref >= 1 && suff >= 1) {
                    dp[i] = 2;
                    res++;
                }
            }
        }

        return res;
    }
};

int howManySatisfy(int n, int k, vector<int>& a) {
    int res = 0;
    vector<int>dp(n, 0);
    int sum = 0;
    for(int i = 0; i < k; i++) {
        sum += a[i];
    }

    dp[0] = sum;
    for(int i = k; i < n; i++) {
        sum -= a[i-k];
        sum += a[i];
        dp[i-k+1] = sum;
    }

    for(int i = 0; i <= n-2*k; i++) {
        int p = dp[i];
        int q = dp[i+k];
        if(p > q) res++;
    }

    return res;
}

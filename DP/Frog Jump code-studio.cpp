// Tabulation method

#include <bits/stdc++.h> 
int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    vector<int>dp(n,-1);
    dp[0] = 0;
    for(int i=1 ; i<n ; i++) {
        int first = dp[i-1] + abs(heights[i] - heights[i-1]);
        int second = INT_MAX;
        if(i>1) {
            second = dp[i-2] + abs(heights[i] - heights[i-2]);
        }
        dp[i] = min(first, second);
    }
    return dp[n-1];
}



Code studio



// Space Optimization solution
// like fibonaccii

#include <bits/stdc++.h> 
int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    // vector<int>dp(n,-1);
    // dp[0] = 0;
    int a = 0;
    int b = 0, c;
    for(int i=1 ; i<n ; i++) {
        int first = a + abs(heights[i] - heights[i-1]);
        int second = INT_MAX;
        if(i>1) {
            second = b + abs(heights[i] - heights[i-2]);
        }
        c = min(first, second);
        b = a;
        a = c;
    }
    return c;
}


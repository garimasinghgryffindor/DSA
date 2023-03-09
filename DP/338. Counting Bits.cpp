class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>dp(n+1);
        dp[0] = 0;
        for(int i=1 ; i<=n ; i++) {
            dp[i] = dp[i/2] + i%2;
        }
        
        return dp;
    }
};

// 0->0  2->10  4->100  6->110  8->1000  10->1010  12->1100  14->1110
// 1->1  3->11  5->101  7->111  9->1001  11->1011  13->1101  15->1111



Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.

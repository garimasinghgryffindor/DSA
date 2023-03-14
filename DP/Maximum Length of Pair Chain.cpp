class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs .end());
        // assuming this question like solving subsequences
        // let's try solving using the longest increasing subsequence approach
        int n = pairs.size();
        vector<int> dp(n,1);
        
        for(int i=1 ; i<n ; i++) {
            for(int j=0 ; j<i ; j++) {
                if(pairs[i][0] > pairs[j][1]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        
        return dp[n-1];
    }
};



Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.

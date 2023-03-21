bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n = arr.size();
        bool dp[n+1][sum+1];
        
        // if sum is zero then ans true
        for(int i=0 ; i<n+1 ; i++) {
            dp[i][0] = true;
        }
        
        // if sum!=0 and elements=0 -> ans false
        for(int i=1 ; i<sum+1 ; i++) {
            dp[0][i] = false;
        }
        
        for(int i=1 ; i<=n ; i++) {
            for(int j=1 ; j<=sum ; j++) {
                if(j < arr[j]) {
                    dp[i][j] = dp[i-1][j];
                }
                else {
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
                }
            }
        }
        
        return dp[n][sum];
    }

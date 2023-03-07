like frog jumps questions from codestudio
except for the fact that we can make k jumps instead of 1 and 2
  
int f(int n, vector<int>&heights, int k)
{
  vector<int>dp(n,INT_MAX);
  dp[0] = 0;
  for(int i=1 ; i<n ; i++)
  {
    for(int j=1 ; j<=k ; j++)
    {
      int x = INT_MAX;
      if(i-j >= 0)
      {
        x = dp[i-j] + abs(heights[i] - heights[i-j]);
      }
      dp[i] = min(dp[i], x);
    }
  }
  
  return dp[n-1];
}




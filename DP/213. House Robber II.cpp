USING TABULATION

class Solution {
public:
    int rob(vector<int>& nums) {
        // very similar to the house robber I problem
        // so the gist is that..
        // the robber cannot rob the house 1 and house last at the same time..
        // so it has to be either house I or house last
        // so we will apply the same logic as house robber I (DP)
        // first in array ->  [0 ,  last-1]
        // second in array->  [1,   last]
        int n = nums.size();
        if(n==0)
            return 0;
        if(n==1)
            return nums[0];
        if(n==2)
            return max(nums[0], nums[1]);
        
        vector<int> dp(n-1 , 0);
        int res1=0, res2=0;
        
        // computing the first result
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        
        for(int i=2 ; i<n-1 ; i++) {
            dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
        }
        
        res1 = dp[n-2];
        
        //computing the second result
        dp.resize(n , 0);
        dp[1] = nums[1];
        dp[2] = max(nums[1], nums[2]);
        
        for(int i=3 ; i<n ; i++) {
            dp[i] = max(dp[i-1] , dp[i-2]+nums[i]);
        }
        
        res2 = dp[n-1];
        
        return max(res1, res2);
        
    }
};





USING SPACE OPTIMIZATION


class Solution {
public:
    int rob(vector<int>& nums) {
        // very similar to the house robber I problem
        // so the gist is that..
        // the robber cannot rob the house 1 and house last at the same time..
        // so it has to be either house I or house last
        // so we will apply the same logic as house robber I (DP)
        // first in array ->  [0 ,  last-1]
        // second in array->  [1,   last]
        int n = nums.size();
        if(n==0)
            return 0;
        if(n==1)
            return nums[0];
        if(n==2)
            return max(nums[0], nums[1]);
        
        // vector<int> dp(n-1 , 0);
        
        int res1=0, res2=0;
        
        // computing the first result
        int a = nums[0];
        int b = max(nums[0], nums[1]);
        int c;
        // dp[0] = nums[0];
        // dp[1] = max(nums[0], nums[1]);
        
        for(int i=2 ; i<n-1 ; i++) {
            // dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
            c = max(b, a + nums[i]);
            a = b;
            b = c;
        }
        
        res1 = c;
        
        //computing the second result
        // dp.resize(n , 0);
        a = nums[1];
        b = max(nums[1], nums[2]);
        c = max(a,b);
        // dp[1] = nums[1];
        // dp[2] = max(nums[1], nums[2]);
        
        for(int i=3 ; i<n ; i++) {
            c = max(b , a + nums[i]);
            a = b;
            b = c;
        }
        
        res2 = c;
        
        return max(res1, res2);
        
    }
};

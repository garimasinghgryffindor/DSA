class Solution {
public:
    int dp[(1<<16)+1][4];
    int recur(vector<int>&nums,int len, int AND) {
        if(len == 4) {
            return AND==0;
        }
        
        if(dp[AND][len] != -1)
            return dp[AND][len];
        
        int res = 0;
        
        for(int i=0 ; i<nums.size() ; i++) {
            res += recur(nums,len+1,(AND&nums[i]));
        }
        
        return dp[AND][len] = res;
    }
    
    int countTriplets(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return recur(nums,1,pow(2,16)-1);
    }
};

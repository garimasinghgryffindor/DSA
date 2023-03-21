class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> jobs;
        for(int i=0 ; i<n ; i++){
            jobs.push_back({startTime[i],endTime[i],profit[i]});
        }
        sort(jobs.begin(),jobs.end());
        vector<int>dp(n+1,0);
        map<int,int>mp;
        for(int i=n-1 ; i>=0 ; i--){
            int st = jobs[i][0];
            int end = jobs[i][1];
            auto it = mp.lower_bound(end);
            dp[i] = max(dp[i+1] , jobs[i][2]+(*it).second);
            mp[st] = dp[i];
        }
        return dp[0];
    }
};


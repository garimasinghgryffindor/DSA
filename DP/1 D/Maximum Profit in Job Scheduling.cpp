class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> jobs;
        for(int i=0 ; i<n ; i++) {
            jobs.push_back({endTime[i], startTime[i], profit[i]});
        }
        
        sort(jobs.begin(), jobs.end());
        
        map<int,int> dp = {{0,0}};
        //endTime, profit
        
        // we will go through all the jobs one by one.
        
        for(int i=0 ; i<n ; i++) {
            auto job = jobs[i];
            // profit in taking up the current job
            // dp.upper_bound(x) will get the map iterator with key < current job starting time.
            // and since we do not want any overlap we are going to take the previous job's total cumulative profit to add up to the current job profit
            
            int currProfit = prev(dp.upper_bound(job[1]))->second + job[2];
            
            if(currProfit > dp.rbegin()->second) {
                dp[job[0]] = currProfit;
            }
        }
        
        return dp.rbegin()->second;
    }

};

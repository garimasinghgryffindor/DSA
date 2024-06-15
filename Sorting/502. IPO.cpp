class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int res = 0, n = profits.size();
        vector<pair<int,int>> jobs;
        for(int i=0 ; i<n ; i++) {
            jobs.push_back({profits[i],capital[i]});
        }
        sort(jobs.begin(), jobs.end(),[&](pair<int,int> a,pair<int,int> b){ return a.second<b.second;});
        
        priority_queue<int> maxProfit;
        
        vector<bool>visited(n,false);
        int i=0;
        while(k--) {
            while(i<n && w>=jobs[i].second) {
                // i.e; greater than equal to the capital
                maxProfit.push(jobs[i++].first);
            }
            
            if(!maxProfit.empty()) {
                w+=maxProfit.top();
                maxProfit.pop();
            }
        }
        
        return w;
    }
};

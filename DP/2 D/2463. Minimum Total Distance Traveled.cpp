#define ll long long
class Solution {
public:
    ll mx = (ll)1e13;
    long long recur(vector<int>& robot, vector<int>&factory, int rb, int fct, vector<vector<ll>>&dp) {
        if(rb >= robot.size()) return 0;
        if(fct >= factory.size()) return mx;
        
        if(dp[rb][fct] != -1) return dp[rb][fct];
        
        ll res = mx;
        
        res = min(res, abs(factory[fct]-robot[rb]) + recur(robot, factory, rb+1, fct+1, dp));
        res = min(res, recur(robot, factory, rb, fct+1, dp));
        
        return (dp[rb][fct] = res);
    }
    
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        vector<int> fact;
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        int n = robot.size(), m = factory.size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < factory[i][1]; j++) {
                fact.push_back(factory[i][0]);
            }
        }
        vector<vector<ll>>dp(n, vector<ll>(fact.size(), -1));
        return recur(robot, fact, 0, 0, dp);
    }
};

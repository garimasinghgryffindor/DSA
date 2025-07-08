
class Solution {
public:
    vector<vector<int>> dp;

    int recur(vector<vector<int>>& events, vector<int>& startTimes, int idx, int k) {
        if (idx >= events.size() || k == 0) return 0;
        if (dp[idx][k] != -1) return dp[idx][k];

        // Option 1: Skip this event
        int notTake = recur(events, startTimes, idx + 1, k);

        // Option 2: Take this event
        int nextIdx = lower_bound(startTimes.begin(), startTimes.end(), events[idx][1] + 1) - startTimes.begin();
        int take = events[idx][2] + recur(events, startTimes, nextIdx, k - 1);

        return dp[idx][k] = max(take, notTake);
    }

    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());  // sort by start time
        int n = events.size();
        dp.assign(n + 1, vector<int>(k + 1, -1));

        vector<int> startTimes(n);
        for (int i = 0; i < n; ++i) {
            startTimes[i] = events[i][0];
        }

        return recur(events, startTimes, 0, k);
    }
};

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        vector<pair<double, int>> vec;
        int n = quality.size();
        for(int i = 0; i < n; i++) {
            vec.push_back({(double)wage[i]/quality[i], i});
        }
        
        sort(vec.begin(), vec.end());
        
        double mxRate = 0.0;
        priority_queue<int> maxHeap;
        int qualitySum = 0;
        
        for(int i = 0; i < k; i++) {
            mxRate = max(mxRate, vec[i].first);
            qualitySum += quality[vec[i].second];
            maxHeap.push(quality[vec[i].second]);
        }
        
        double res = qualitySum * mxRate;
        
        for(int i = k; i < n; i++) {
            mxRate = max(mxRate, vec[i].first);
            int tp = maxHeap.top();     maxHeap.pop();
            qualitySum -= tp;
            qualitySum += quality[vec[i].second];
            maxHeap.push(quality[vec[i].second]);
            res = min(res, mxRate*qualitySum);
        }
        
        return res;
    }
};

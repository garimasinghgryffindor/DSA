
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<long long> res(n, 0);
        vector<long> rooms(n, -1);
        sort(meetings.begin(), meetings.end());
        int sz = meetings.size();
        
        priority_queue<pair<long long, long long>, vector<pair<long long, long long> >, greater<pair<long long, long long> > > pq;
        priority_queue<long long, vector<long long>, greater<long long> > pq_id;
        
        for(int i = 0; i < n; i++) {
            pq_id.push(i);
        }
        
        for(int i = 0; i < sz; i++) {
            long long start = meetings[i][0], end = meetings[i][1];
            
            while(!pq.empty() && (pq.top()).first <= start) {
                pq_id.push((pq.top()).second);
                pq.pop();
            }
            
            if(!pq_id.empty()) {
                long long id_lowest = pq_id.top();
                pq_id.pop();
                res[id_lowest]++;
                pq.push({end, id_lowest});
            } else {
                long long id_lowest = (pq.top()).second;
                long long endingTime = (pq.top()).first;
                pq.pop();
                pq.push({endingTime+(end-start), id_lowest});
                res[id_lowest]++;
            }
        }
        
        int ans = -1;
        
        for(int i = 0; i < n; i++) {
            if(ans == -1 || res[ans] < res[i]) {
                ans = i;
            }
        }
        
        return ans;
    }
};

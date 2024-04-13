class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<int> res(n, -1);
        priority_queue<pair<int, int>, vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0, 0});
        
        vector<vector<pair<int,int> > > graph(n);
        for(auto edge: edges) {
            int u = edge[0], v = edge[1], time = edge[2];
            graph[u].push_back({v, time});
            graph[v].push_back({u, time});
        }
        
        while(!pq.empty()) {
            auto tp = pq.top();     pq.pop();
            int node = tp.second;
            int time = tp.first;
            
            if(res[node] != -1) continue;
            res[node] = time;
            
            for(auto x: graph[node]) {
                int n1 = x.first;
                int t1 = x.second;
                if(res[n1] == -1 && time+t1 < disappear[n1]) {
                    pq.push({time+t1, n1});
                }
            }
        }
        
        return res;
    }
};

class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        // let us try using SSSP
        // using Dijkstra's Algorithm
        
        // first off we will create an adjacency list
        vector<int> graph[n];
        
        for(int i = 0; i < n; i++) {
            int from = manager[i];
            int to = i;
            
            if(from == -1) continue;
            graph[from].push_back(to);
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int> >,greater<pair<int,int> > > pq;
        
        pq.push({0,headID});
        vector<int>costs(n, INT_MAX);
        costs[headID] = 0;
        int res = 0;
        
        while(!pq.empty()) {
            int node = pq.top().second;
            int wt = pq.top().first;
            pq.pop();
            
            for(auto x: graph[node]) {
                int neighbour = x;
                int costHere = informTime[node] + wt;
                if(costs[neighbour] > costHere) {
                    costs[neighbour] = costHere;
                    pq.push({costHere, neighbour});
                }
            }
        }
        
        for(int i = 0; i < n; i++) {
            res = max(res, costs[i]);
        }
        
        return res;
    }
};

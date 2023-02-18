class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int res = 0;
        
        // graph creation  ->  adjacency list
        int maxWeight=0;
        vector<pair<int,int>> graph[n+1];
        for(auto x: times) {
            int u = x[0], v = x[1] , w = x[2];
            graph[u].push_back({v,w});
            maxWeight = max(maxWeight,w);
        }
        
        vector<int> time(n+1,INT_MAX);
        queue<int> q[maxWeight+1];
        time[k] = 0;
        
        q[0].push(k);
        
        while(1) {
            int flag = 0;
            for(int i=0 ; i<=maxWeight ; i++) {
                while(!q[i].empty()) {
                    flag = 1;
                    int x = q[i].front();
                    q[i].pop();
                    
                    if(!graph[x].empty())
                    for(auto node: graph[x]) {
                        int v = node.first;
                        int w = node.second;
                        if(time[v] > time[x] + w) {
                            time[v] = time[x] + w;
                            q[w].push(v);
                        }
                    }
                }
            }
            
            if(flag == 0)
                break;
        }
        
        for(int i=1 ; i<n+1 ; i++) {
            if(time[i] > res) {
                res = time[i];
            }
            if(time[i] == INT_MAX)
                return -1;
        }
        
        return res;
    }
};




LEETCODE 743
  
You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.



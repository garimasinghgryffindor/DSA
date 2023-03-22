class Solution {
public:
    
    void dfs(vector<pair<int,int>>graph[],int n, int &minx,int source,vector<bool>&vis) {
        if(vis[source])
            return;
        
        vis[source] = true;
        for(auto x: graph[source]) {
            int node = x.first;
            int wt = x.second;
            minx = min(minx,wt);
            dfs(graph,n,minx,node,vis);
        }
    }
    
    int minScore(int n, vector<vector<int>>& roads) {
        int min = INT_MAX;
        // adjacency list
        vector<pair<int,int>> graph[n+1];
        for(auto road: roads) {
            int st = road[0], end = road[1], dist = road[2];
            graph[st].push_back({end, dist});
            graph[end].push_back({st, dist});
        }
        vector<bool>vis(n+1,false);
        dfs(graph,n,min,1,vis);
        
        return min;
    }
};


class Solution {
  public:
   vector<int>res;
    vector<int>count;
    
    void dfs(vector<vector<int>>&graph, int node, int parent) {
        for(int child: graph[node]) {
            if(child == parent) continue;
            dfs(graph, child, node);
            count[node] += count[child];
            res[node] += count[child] + res[child];
        }
    }
    
    void dfs2(vector<vector<int>>&graph, int node, int parent) {
        for(int child: graph[node]) {
            if(child == parent) continue;
            
            res[child] = res[node] - count[child] + (count.size() - count[child]);
            dfs2(graph, child, node);
        }
    }
    
    int optimalCaptial(int n, int m, vector<vector<int>> &roads) {
         res.resize(n, 0);
        count.resize(n, 1);
        
        vector<vector<int>>graph(n);
        for(auto x: roads) {
            int u = x[0];
            int v = x[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        dfs(graph, 0, -1);
        dfs2(graph, 0, -1);
        
        int ans = 0;
        for(int i = 1; i < n; i++) {
            if(res[i] < res[ans]) {
                ans = i;
            }
        }
        
        return ans;
        
    }
};

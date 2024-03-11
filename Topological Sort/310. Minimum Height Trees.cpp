class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0};
        
        vector<int> res;
        vector<int>adj[n];
        vector<int>indegree(n, 0);
        
        for(auto edge: edges) {
            int x = edge[0], y = edge[1];
            adj[x].push_back(y);
            adj[y].push_back(x);
            indegree[x]++;
            indegree[y]++;
        }
        
        queue<int>q;
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 1) {
                // i.e; leaf nodes
                q.push(i);
                indegree[i]--;
            }
        }
        
        while(!q.empty()) {
            int sz = q.size();
            
            res.clear();
            
            for(int i = 0; i < sz; i++) {
                int node = q.front();     q.pop();
                res.push_back(node);
                for(auto x: adj[node]) {
                    indegree[x]--;
                    if(indegree[x] == 1) q.push(x);
                }
            }
        }
        
        return res;
    }
};



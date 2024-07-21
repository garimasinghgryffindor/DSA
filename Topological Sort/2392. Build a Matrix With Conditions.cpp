class Solution {
public:
    bool ans = true;
    void dfs(vector<vector<int>>& graph, int pos, vector<int>& res, vector<bool>& visited, vector<bool>& vis) {
        if (vis[pos]) {
            ans = false;
            return;
        }
        
        if (visited[pos]) {
            return;
        }
        
        visited[pos] = true;
        vis[pos] = true;
        
        for (int i : graph[pos]) {
            if (!visited[i]) {
                dfs(graph, i, res, visited, vis);
            } else if (vis[i]) {
                ans = false;
                return;
            }
        }
        
        vis[pos] = false; // Reset vis after finishing the DFS for this node
        res.push_back(pos);
    }
    
    void topologicalSort(vector<vector<int>>& vec, int k, vector<int>&res) {
        vector<vector<int>>graph(k+1);
        for(int i = 0; i < vec.size(); i++) {
            int u = vec[i][0];
            int v = vec[i][1];
            graph[u].push_back(v);
        }
        
        vector<bool>visited(k+1, false);
        vector<bool>vis(k+1, false);
        for(int i = 1; i <= k; i++) {
            if(!visited[i]) {
                dfs(graph, i, res, visited, vis);
            }
        }
        
        reverse(res.begin(), res.end());
    }
    
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int>>res(k, vector<int>(k, 0));
        
        // using topological sorting
        vector<int>rows, cols;
        
        topologicalSort(rowConditions, k, rows);
        if(!ans) return {};
        topologicalSort(colConditions, k, cols);
        if(!ans) return {};
        
        vector<int>indicesR(k+1, 0), indicesC(k+1, 0);
        for(int i = 0; i < k; i++) {
            indicesR[rows[i]] = i;
            indicesC[cols[i]] = i;
        }
        
        for(int i = 1; i <= k; i++) {
            res[indicesR[i]][indicesC[i]] = i;
        }
        
        return res;
        
    }
};

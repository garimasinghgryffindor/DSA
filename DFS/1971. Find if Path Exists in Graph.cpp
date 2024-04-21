class Solution {
public:
    
    bool dfs(vector<vector<int>>& graph, vector<bool>& visited,int target,int current) {
        
        if(visited[current] == true) return false;
        
        if(current == target) return true;
        
        visited[current] = true;
        
        for(int i = 0 ; i < graph[current].size(); i++) {
            if(dfs(graph,visited,target,graph[current][i])) return true;
        }
        
        return false;
        
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int &start, int &end) {
        
        vector<vector<int>> graph(n);
        
        for(int ctr = 0 ; ctr < edges.size() ; ctr ++) {
            
            int first = edges[ctr][0], second = edges[ctr][1];
            
            graph[first].push_back(second);
            graph[second].push_back(first);
            
        }
        
        vector<bool> visited(n,false);
        
        if(dfs(graph, visited, end, start)) return true;
        
        return false;
        
    }
};

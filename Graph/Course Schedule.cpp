// we are using the coloring algorithm
// using DFS
class Solution {
public:
    
    bool dfsUtils(vector<int>graph[],int V,vector<int>&vis,int s) {
        if(vis[s] == 1) 
            return false;
        
        if(vis[s] == 0)
        {
            vis[s] = 1;
            for(auto x: graph[s]) {
                bool res = dfsUtils(graph,V,vis,x);
                if(res == false)
                    return false;
            }
        }
        
        vis[s] = 2;
        return true;
    }
    
    bool dfs(vector<int>graph[], int V)
    {
        vector<int> vis(V,0);
        for(int i=0 ; i<V ; i++) {
            bool res = dfsUtils(graph,V,vis,i);
            if(res == false) {
                return false;
            }
        }
        
        return true;
    }
    
    bool canFinish(int V, vector<vector<int>>& prerequisites) {
        
        vector<int>graph[V];
        for(auto x: prerequisites) {
            int u = x[0], v = x[1];
            graph[u].push_back(v);
        }
        
        return dfs(graph,V);
        
        return true;
    }
};


// using BFS
class Solution {
public:
    
    bool canFinish(int V, vector<vector<int>>& prerequisites) {
        // if there's a cycle in the graph then not possible to take all courses.
        // else if there's no cycle -> possible
        vector<int>graph[V];
        for(auto x: prerequisites) {
            int u = x[0], v = x[1];
            graph[u].push_back(v);
        }
            
        vector<int>indegree(V, 0);
        for(int i=0 ; i<V ; i++) {
            for(int x: graph[i]) {
                indegree[x]++;
            }
        }
        
        queue<int>q;
        for(int i=0 ; i<V ; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        
        int count = 0;
        while(!q.empty()) {
            int frnt = q.front();
            q.pop();
            count++;
            for(int x: graph[frnt]) {
                indegree[x]--;
                if(indegree[x] == 0) {
                    q.push(x);
                }
            }
        }
        
        return count == V;
    }

};


// using Topological Sort
// Kahn's Algorithm
class Solution {
public:
    void topological(vector<int>graph[], int idx, vector<bool>&vis, stack<int>&st) {
        vis[idx] = true;
        for(int x : graph[idx]) {
            if(!vis[x])
                topological(graph, x, vis, st);
        }
        st.push(idx);
    }
    
    bool canFinish(int V, vector<vector<int>>& prerequisites) {
        // if there's a cycle in the graph then not possible to take all courses.
        // else if there's no cycle -> possible
        vector<int>graph[V];
        stack<int>st;
        vector<bool>vis(V, false);
        vector<int> topo(V);
        int count = 0;
        for(auto x: prerequisites) {
            int u = x[0], v = x[1];
            graph[u].push_back(v);
        }
       
        for(int i=0 ; i<V ; i++) {
            if(!vis[i]) {
                topological(graph, i, vis, st);
            }
        }
        
        while(!st.empty()) {
            topo[st.top()] = count++;
            st.pop();
        }
        
        for(int i=0 ; i<V ; i++){
            for(int it: graph[i])
                if(topo[i] >= topo[it])
                    return false;
        }
        
        return true;
    }

};






LEETCODE 207
 

There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.



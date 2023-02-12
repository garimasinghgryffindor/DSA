class Solution {
public:
    long long fuel;
    
    long long dfs(vector<vector<int>>&graph,int parent,int v,int&seats) {
        int res = 1;
        for(auto& x: graph[v]) {
            if(x!=parent) {
                res += dfs(graph,v,x,seats);
            }
        }
        
        if(v!=0) {
            fuel += ceil((double)res/seats);
        }
        
        return res;
    }
    
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size()+1;
        vector<vector<int>> graph(n);
        for(int i=0 ; i<roads.size() ; i++) {
            int u = roads[i][0], v = roads[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        dfs(graph,-1,0,seats);
        
        return fuel;
    }
};



LEETCODE 2477
  
There is a tree (i.e., a connected, undirected graph with no cycles) structure country network consisting of n cities numbered from 0 to n - 1 and exactly n - 1 roads. The capital city is city 0. You are given a 2D integer array roads where roads[i] = [ai, bi] denotes that there exists a bidirectional road connecting cities ai and bi.

There is a meeting for the representatives of each city. The meeting is in the capital city.

There is a car in each city. You are given an integer seats that indicates the number of seats in each car.

A representative can use the car in their city to travel or change the car and ride with another representative. The cost of traveling between two cities is one liter of fuel.

Return the minimum number of liters of fuel to reach the capital city.






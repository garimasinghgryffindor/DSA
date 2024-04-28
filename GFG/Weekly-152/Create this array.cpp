class Solution {
  public:
    vector<int> createArray(int M, int N, vector<vector<int>> &Requirements) {
        // code here
        vector<int>res(N, 1);
        vector<int>indegree(N, 0);
        vector<vector<int>> graph(N);
        for(int i = 0; i < Requirements.size(); i++) {
            int u = Requirements[i][0];
            int v = Requirements[i][1];
            indegree[v]++;
            graph[u].push_back(v);
        }
        
        queue<int>q;
        for(int i = 0; i < N; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        int count = 1;
        while(!q.empty()) {
            int sz = q.size();
            for(int i = 0; i < sz; i++) {
                int tp = q.front();     q.pop();
                res[tp] = count;
                for(int x: graph[tp]) {
                    indegree[x]--;
                    if(indegree[x] == 0) {
                        q.push(x);
                    }
                }
            }
            count++;
        }
        
        return res;
    }
};

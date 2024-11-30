class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        vector<vector<int>> res;
        int n = pairs.size();
        unordered_map<int, int>indegree, outdegree;
        unordered_map<int, vector<int>> graph;
        for(auto x: pairs) {
            indegree[x[0]]++;
            outdegree[x[1]]++;
            graph[x[0]].push_back(x[1]);
        }

        int start = pairs[0][0];
        for(auto node: graph) {
            if(indegree[node.first] > outdegree[node.first]) {
                start = node.first;
                break;
            }
        }

        stack<int>st;
        deque<int>path;
        st.push(start);
        while(!st.empty()) {
            int tp = st.top();
            if(!graph[tp].empty()) {
                st.push(graph[tp].back());
                graph[tp].pop_back();
            } else {
                path.push_front(tp);
                st.pop();
            }
        }

        // bool first = true;
        int prev = -1;
        for(auto x: path) {
            if(prev != -1) {
                res.push_back({prev, x});
                prev = x;
            } else {
                prev = x;
            }
        }
        return res;
    }
};

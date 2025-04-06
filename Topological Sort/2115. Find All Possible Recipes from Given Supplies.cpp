class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        vector<string>res;
        unordered_map<string, int>indegree;
        unordered_map<string, vector<string>> graph;
        for(int i = 0; i < recipes.size(); i++) {
            indegree[recipes[i]] = ingredients[i].size();
        }

        for(int i = 0; i < recipes.size(); i++) {
            for(int j = 0; j < ingredients[i].size(); j++) {
                graph[ingredients[i][j]].push_back(recipes[i]);
            }
        }

        queue<string>q;

        for(auto x: supplies) {
            q.push(x);
        }

        while(!q.empty()) {
            for(int i = 0; i < q.size(); i++) {
                string x = q.front();   q.pop();
                for(auto y: graph[x]) {
                    indegree[y]--;
                    if(indegree[y] == 0) {
                        q.push(y);
                        res.push_back(y);
                    }
                }
            }
        }

        return res;
    }
};

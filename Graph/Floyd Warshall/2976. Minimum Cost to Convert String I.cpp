class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        long long res = 0;
        int n = 26;
        vector<vector<long long>>floyd (n, vector<long long>(n, INT_MAX));
        for(int i = 0; i < original.size(); i++) {
            int u = original[i]-'a';
            int v = changed[i]-'a';
            floyd[u][v] = min(floyd[u][v], (long long)cost[i]);
        }

        for(int i = 0; i < 26; i++) floyd[i][i] = 0;

        for(int k = 0; k < 26; k++) {
            for(int i = 0; i < 26; i++) {
                for(int j = 0; j < 26; j++) {
                    if(floyd[i][k] != INT_MAX && floyd[k][j] != INT_MAX) {
                        floyd[i][j] = min(floyd[i][j], (long long)floyd[i][k] + floyd[k][j]);
                    }
                }
            }
        }

        for(int i = 0; i < source.length(); i++) {
            if(source[i] == target[i]) {
                // all good

            } else {
                if(floyd[source[i]-'a'][target[i]-'a'] != INT_MAX) {
                    res += floyd[source[i]-'a'][target[i]-'a'];
                } else return -1;
            }
        }

        return res;
    }
};

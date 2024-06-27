class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size();
        unordered_map<int,int> freq;
        for(int i=0 ; i<edges.size() ; i++) {
            freq[edges[i][0]]++;
            freq[edges[i][1]]++;
            if(freq[edges[i][0]] > 1){
                return edges[i][0];
            }
            if(freq[edges[i][1]] > 1){
                return edges[i][1];
            }
        }
        return 0;
    }
};

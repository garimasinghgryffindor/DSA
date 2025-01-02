class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size(), q = queries.size();
        vector<int>res(q, 0);
        vector<int>vec(n+1, 0);
        for(int i = 0; i < n; i++) {
            auto x = words[i];
            auto st = x[0];
            auto end = x[x.length() - 1];
            if((st=='a' || st=='e' || st=='i' || st=='o' || st=='u') && (end=='a' || end=='e' || end=='i' || end=='o' || end=='u')) {
                vec[i+1] = 1;
            }
            
            vec[i+1] += vec[i];
        } 

        for(int i = 0; i < q; i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            res[i] = vec[r+1] - vec[l];
        }

        return res;
    }
};

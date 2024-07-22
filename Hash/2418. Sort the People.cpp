class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        unordered_map<int, string> mp;
        int n = names.size();
        for(int i = 0; i < n; i++) {
            mp[heights[i]] = names[i];
        }
        
        sort(heights.rbegin(), heights.rend());
        vector<string>res;
        
        for(int i = 0; i < n; i++) {
            res.push_back(mp[heights[i]]);
        }
        return res;
    }
};

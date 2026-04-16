class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        vector<int>res;
        int n = nums.size();
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        for(int q: queries) {
            int key = nums[q];
            if(mp[key].size() == 1) {
                res.push_back(-1);
                continue;
            }
            int pos_of_key_in_map = lower_bound(mp[key].begin(), mp[key].end(), q) - mp[key].begin();
            int dist = INT_MAX;
            // checking left
            int key_size = mp[key].size();
            int l = mp[key][(pos_of_key_in_map-1+key_size)%key_size];
            int d1 = abs(q-l);
            dist = min({dist, d1, n-d1});
            // checking right
            int r = mp[key][(pos_of_key_in_map+1)%key_size];
            int d2 = abs(q-r);
            dist = min({dist, d2, n-d2});
            res.push_back(dist);
        }

        return res;
    }
};

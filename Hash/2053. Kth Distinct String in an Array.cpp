class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int>mp;
        for(auto x: arr) {
            mp[x]++;
        }
        
        int cnt = 0;
        for(auto x: arr) {
            if(mp[x] == 1) {
                cnt++;
                if(cnt == k) return x;
            }
        }
        return "";
    }
};

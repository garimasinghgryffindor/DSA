class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> mp;
        int mx = 0;
        for(int x: nums) {
            mp[x]++;
            mx = max(mx, mp[x]);
        }
        
        int res = 0;
        for(auto x: mp) {
            if(x.second == mx) {
                res += mx;
            }
        }
        
        return res;
    }
};

class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int>mp;
        for(int a: nums) {
            if(mp.find(a) == mp.end()) {
                string x = to_string(a);
                string xx = "";
                for(int i = 0; i < x.length(); i++) {
                    xx += to_string(mapping[x[i]-'0']);
                }
                int x_ = stoi(xx);
                mp[a] = x_;
            }
        }
        
        sort(nums.begin(), nums.end(), [&](int a, int b) {
            if(mp[a] < mp[b]) return true;
            else return false;
        });
        return nums;
    }
};




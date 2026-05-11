class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> res;
        for(int x: nums) {
            string s = to_string(x);
            // cout<<s<<endl;
            for(auto ch: s) {
                res.push_back(ch-'0');
            }
        }
        return res;
    }
};

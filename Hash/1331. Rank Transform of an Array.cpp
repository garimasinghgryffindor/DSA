class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>res(arr.size());
        map<int, int> mp;
        for(int i = 0; i < arr.size(); i++) {
            mp[arr[i]] = 1;
        }
        int cnt = 1;
        for(auto x: mp) {
            mp[x.first] = cnt;
            cnt++;
        }
        for(int i = 0; i < arr.size(); i++) {
            res[i] = mp[arr[i]];
        }
        return res;
    }
};

// 5, 9, 12, 28, 37, 56, 80, 100
// 1. 2. 3.  4.  5.  6.  7.  8



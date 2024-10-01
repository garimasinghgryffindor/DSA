class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        for(int x: arr) {
            mp[((x%k)+ k)%k]++;
        }
        
        for(auto x: mp) {
            if(x.first == 0) {
                if(x.second % 2 == 1) return false;
            } else if(k - x.first == x.first) {
                if(x.second %2 == 1) return false;
            } else {
                if(x.second != mp[k-x.first]) return false;
            }
        }
        return true;
    }
};

// 1 2 3 4 0 1 2 3 4 0

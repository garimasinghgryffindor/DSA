// approach 1 using hashing
class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> mp;
        unordered_map<char, bool> mp2;
        for(auto x: s) {
            mp[x]++;
        }
        
        for(auto x: order) {
            mp2[x] = true;
        }
        
        string res;
        for(auto x: order) {
            if(mp.find(x) != mp.end()) {
                int count = mp[x];
                while(count--) {
                    res = res + x;
                }
            }
        }
        
        for(auto x: s) {
            if(mp2.find(x) == mp2.end()) {
                res = res+x;
            }
        }
        
        return res;
    }
};

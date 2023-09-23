class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int>mp;
        int res = 0;
        int n = s.length();
        int l = 0, r = 0;
        while(r < n) {
            if(mp.find(s[r]) == mp.end()) {
                // well and good
                // this is a unique character
                mp[s[r]] = r;
                res = max(res, r-l+1);
                r++;
            } else {
                // dupe character
                // find its last position
                int last = mp[s[r]];
                l = max(l, last+1);
                res = max(res, r - l + 1);
                mp[s[r]] = r;
                r++;
            }
        }
        
        return res;
    }
};

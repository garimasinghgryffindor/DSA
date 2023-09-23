int longestKSubstr(string s, int k) {
        // your code here
        int res = 0;
        unordered_map<char,int>mp;
        int l = 0, r = 0;
        while(r < s.length()) {
            mp[s[r]]++;
            if(mp.size() < k) {
                r++;
            } else if(mp.size() == k) {
                res = max(res, r-l+1);
                r++;
            } else {
                while(mp.size() > k) {
                    mp[s[l]]--;
                    if(mp[s[l]] == 0) {
                        mp.erase(s[l]);
                    }
                    l++;
                }
                r++;
            }
        }
        return res;
    }

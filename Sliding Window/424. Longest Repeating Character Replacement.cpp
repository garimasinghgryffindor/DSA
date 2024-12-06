class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mp;
        int n = s.length();
        int l = 0;
        // int prevmax = 0;
        int res = 0;
        int prevmax = 0;
        for(int r = 0; r < n; r++) {
            mp[s[r]]++;
            prevmax = max(prevmax, mp[s[r]]);
            int window = r-l+1;
            if(window - prevmax <= k) {
                res = max(res, window);
            } else {
                while(r - l > k) {
                    mp[s[l]]--;
                    l++;
                    int mx = 0;
                    for(auto x: mp) {
                        mx = max(mx, x.second);
                    }
                    int window = r - l + 1;
                    if(window - mx <= k) {
                        // valid window
                        res = max(res, window);
                        prevmax = mx;
                        break;
                    }
                }
            }
        }

        return res;
    }
};

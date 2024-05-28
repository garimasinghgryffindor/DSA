class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int res = 0;
        int curr = 0;
        int i;
        for(i = 0; i < s.length(); i++) {
            // cout<<"executed...... "<<i+1<<endl;
            if(curr + abs(s[i] - t[i]) <= maxCost) {
                curr += abs(s[i] - t[i]);
            } else {
                res = max(res, i);
                break;
            }
        }
        
        if(i == s.length()) return s.length();
        
        int l = 0, r = i;
        while(r < s.length()) {
            curr += abs(s[r] - t[r]);
            while(l <= r && curr > maxCost) {
                curr -= abs(s[l] - t[l]);
                l++;
            }
            res = max(res, r-l+1);
            r++;
        }
        
        return res;
    }
};
